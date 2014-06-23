#include "CTE.h"
    
#define LOG_ERROR(msg) do { std::cerr << "LOG(ERROR): " << msg << " @ (" << __FILE__ << " : " << __LINE__ << ")" << std::endl; assert(0); } while(0)

static const bool verbose = false;
// static const bool verbose = true;

void CTE::init() {
    yuv_to_rgb_inst0.S_U = 0;
    yuv_to_rgb_inst0.S_Y1 = 1;
    yuv_to_rgb_inst0.S_V = 2;
    yuv_to_rgb_inst0.S_BUSY1 = 3;
    yuv_to_rgb_inst0.S_Y2 = 4;
    yuv_to_rgb_inst0.S_BUSY2 = 5;
    // TODO other I/O
    op_mode = 0;
    _protocolState = ProtocolState_s0;
}

void CTE::print() const {
    DEBUG_EXPR(clk);
    DEBUG_EXPR(reset);
    DEBUG_EXPR(op_mode);
    DEBUG_EXPR(in_en);
    DEBUG_EXPR(yuv_in);
    DEBUG_EXPR(rgb_in);

    DEBUG_EXPR(busy);
    DEBUG_EXPR(out_valid);
    DEBUG_EXPR(rgb_out);
    DEBUG_EXPR(yuv_out);

    // Registers
    DEBUG_EXPR(yuv_to_rgb_inst0.state);
    DEBUG_EXPR(yuv_to_rgb_inst0.state_next);
    DEBUG_EXPR(yuv_to_rgb_inst0.reg_U);
    DEBUG_EXPR(yuv_to_rgb_inst0.reg_Y1);
    DEBUG_EXPR(yuv_to_rgb_inst0.reg_V);
    DEBUG_EXPR(yuv_to_rgb_inst0.reg_Y2);

    // Wires
    DEBUG_EXPR(yuv_to_rgb_inst0.reg_U_next);
    DEBUG_EXPR(yuv_to_rgb_inst0.reg_Y1_next);
    DEBUG_EXPR(yuv_to_rgb_inst0.reg_V_next);
    DEBUG_EXPR(yuv_to_rgb_inst0.reg_Y2_next);
    DEBUG_EXPR(yuv_to_rgb_inst0.R_ext);
    DEBUG_EXPR(yuv_to_rgb_inst0.G_ext);
    DEBUG_EXPR(yuv_to_rgb_inst0.B_ext);
    DEBUG_EXPR(yuv_to_rgb_inst0.U_ext);
    DEBUG_EXPR(yuv_to_rgb_inst0.Y_ext);
    DEBUG_EXPR(yuv_to_rgb_inst0.V_ext);
    DEBUG_EXPR(yuv_to_rgb_inst0.R_out);

}
    
void CTE::run(ProtocolEvent e) {
    // DEBUG_EXPR(_protocolState);
    switch(_protocolState) {
        case ProtocolState_s0:
            if (e == ProtocolEvent_reset) {
                _protocolState = ProtocolState_s1;
                compute_reset();
                break;
            }
            else if (e == ProtocolEvent_not_reset) {
                _protocolState  = ProtocolState_s0;
                compute_not_reset();
                break;
            }
            else
                LOG_ERROR("No such branch");
            break;
        case ProtocolState_s1:
S1:
            if (e == ProtocolEvent_reset) {
                _protocolState = ProtocolState_s1;
                compute_reset();
                break;
            }
            else if (e == ProtocolEvent_not_reset) {
                _protocolState = ProtocolState_s2;
                compute_not_reset();
                break;
            }
            else
                LOG_ERROR("No such branch");
        case ProtocolState_s2:
S2:
            if (e == ProtocolEvent_not_reset_and_in_en) {
                _protocolState = ProtocolState_s3;
                read_yuv_in();
                compute_not_reset_and_in_en();
                break;
            }
            else if (e == ProtocolEvent_not_reset) {
                _protocolState = ProtocolState_s2;
                compute_not_reset();
                break;
            }
            else
                LOG_ERROR("No such branch");
        case ProtocolState_s3:
            if (e == ProtocolEvent_not_reset_and_in_en) {
                _protocolState = ProtocolState_s4;
                read_yuv_in();
                compute_not_reset_and_in_en();
                break;
            }
            else
                LOG_ERROR("No such branch");
        case ProtocolState_s4:
            if (e == ProtocolEvent_not_reset_and_in_en) {
                read_yuv_in();
                compute_not_reset_and_in_en();
                if (out_valid) {
                    assert(busy);
                    write_rgb_out();
                    _protocolState = ProtocolState_s5;
                    break;
                }
                else {
                    assert(busy);
                    _protocolState = ProtocolState_s4;
                }
            }
            else
                LOG_ERROR("No such branch");
        case ProtocolState_s5:
            if (e == ProtocolEvent_write_rgb_out) {
                _protocolState = ProtocolState_s7;
                compute_not_reset_and_in_en();
                break;
            }
            else
                LOG_ERROR("No such branch");

        case ProtocolState_s7:
            if (e == ProtocolEvent_not_reset_and_in_en) {
                read_yuv_in();
                compute_not_reset_and_in_en();
                if (out_valid) {
                    assert(busy);
                    write_rgb_out();
                    _protocolState = ProtocolState_s8;
                    break;
                }
                else {
                    assert(busy);
                    _protocolState = ProtocolState_s7;
                }
            }
            else
                LOG_ERROR("No such branch");
            assert(0);
        case ProtocolState_s8:
            if (e == ProtocolEvent_write_rgb_out) {
                _protocolState = ProtocolState_s10;
                compute_not_reset_and_in_en();
                break;
            }
            else
                LOG_ERROR("No such branch");
        case ProtocolState_s10:
            if (e == ProtocolEvent_not_reset_and_in_en) 
                goto S2;
            else if (e == ProtocolEvent_reset)
                goto S1;
            else if (e == ProtocolEvent_not_reset)
                goto S1;
            else 
                LOG_ERROR("No such branch");
    }

}

void CTE::compute_not_reset_and_in_en_and_write_rgb_out() {
    if (verbose)
        std::cout << "compute : " << "not reset and in_en" << std::endl;
    reset = 0;
    in_en = 1;
    compute_all();
}

void CTE::compute_reset() {
    if (verbose)
        std::cout << "compute : " << "reset" << std::endl;
    yuv_to_rgb_inst0.reg_U_next = ((yuv_to_rgb_inst0.state == yuv_to_rgb_inst0.S_U)?yuv_in:yuv_to_rgb_inst0.reg_U);
    yuv_to_rgb_inst0.reg_Y1_next = ((yuv_to_rgb_inst0.state == yuv_to_rgb_inst0.S_Y1)?yuv_in:yuv_to_rgb_inst0.reg_Y1);
    yuv_to_rgb_inst0.reg_V_next = ((yuv_to_rgb_inst0.state == yuv_to_rgb_inst0.S_V)?yuv_in:yuv_to_rgb_inst0.reg_V);
    yuv_to_rgb_inst0.reg_Y2_next = ((yuv_to_rgb_inst0.state == yuv_to_rgb_inst0.S_Y2)?yuv_in:yuv_to_rgb_inst0.reg_Y2);
    yuv_to_rgb_inst0.state_next = ((yuv_to_rgb_inst0.state == yuv_to_rgb_inst0.S_U)?yuv_to_rgb_inst0.S_Y1:((yuv_to_rgb_inst0.state == yuv_to_rgb_inst0.S_Y1)?yuv_to_rgb_inst0.S_V:((yuv_to_rgb_inst0.state == yuv_to_rgb_inst0.S_V)?yuv_to_rgb_inst0.S_BUSY1:((yuv_to_rgb_inst0.state == yuv_to_rgb_inst0.S_BUSY1)?yuv_to_rgb_inst0.S_Y2:((yuv_to_rgb_inst0.state == yuv_to_rgb_inst0.S_Y2)?yuv_to_rgb_inst0.S_BUSY2:((yuv_to_rgb_inst0.state == yuv_to_rgb_inst0.S_BUSY2)?yuv_to_rgb_inst0.S_U:yuv_to_rgb_inst0.state))))));


    yuv_to_rgb_inst0.reg_V = 0; 
    yuv_to_rgb_inst0.reg_U = 0;
    yuv_to_rgb_inst0.reg_Y1 = 0;
    yuv_to_rgb_inst0.reg_Y2 = 0;
    yuv_to_rgb_inst0.state = yuv_to_rgb_inst0.S_U;

    yuv_out = 0;
    yuv_to_rgb_busy = ((yuv_to_rgb_inst0.state == yuv_to_rgb_inst0.S_BUSY1) || (yuv_to_rgb_inst0.state == yuv_to_rgb_inst0.S_BUSY2));
    yuv_to_rgb_out_valid = ((yuv_to_rgb_inst0.state == yuv_to_rgb_inst0.S_BUSY1) || (yuv_to_rgb_inst0.state == yuv_to_rgb_inst0.S_BUSY2));
    out_valid = ((!op_mode)?yuv_to_rgb_out_valid:0);
    busy = ((!op_mode)?yuv_to_rgb_busy:1);
    yuv_to_rgb_inst0.U_ext = (((yuv_to_rgb_inst0.reg_U[7]), (yuv_to_rgb_inst0.reg_U[7]), (yuv_to_rgb_inst0.reg_U[7]), (yuv_to_rgb_inst0.reg_U[7]), (yuv_to_rgb_inst0.reg_U[7]), (yuv_to_rgb_inst0.reg_U[7]), (yuv_to_rgb_inst0.reg_U[7]), (yuv_to_rgb_inst0.reg_U[7])), yuv_to_rgb_inst0.reg_U);
    yuv_to_rgb_inst0.Y_ext = ((yuv_to_rgb_inst0.state == yuv_to_rgb_inst0.S_BUSY1)?(0, yuv_to_rgb_inst0.reg_Y1):(0, yuv_to_rgb_inst0.reg_Y2));
    yuv_to_rgb_inst0.V_ext = (((yuv_to_rgb_inst0.reg_V[7]), (yuv_to_rgb_inst0.reg_V[7]), (yuv_to_rgb_inst0.reg_V[7]), (yuv_to_rgb_inst0.reg_V[7]), (yuv_to_rgb_inst0.reg_V[7]), (yuv_to_rgb_inst0.reg_V[7]), (yuv_to_rgb_inst0.reg_V[7]), (yuv_to_rgb_inst0.reg_V[7])), yuv_to_rgb_inst0.reg_V);
    yuv_to_rgb_inst0.R_ext = ((8 * yuv_to_rgb_inst0.Y_ext) + (13 * yuv_to_rgb_inst0.V_ext));
    yuv_to_rgb_inst0.G_ext = (((8 * yuv_to_rgb_inst0.Y_ext) + (65534 * yuv_to_rgb_inst0.U_ext)) + (65530 * yuv_to_rgb_inst0.V_ext));
    yuv_to_rgb_inst0.B_ext = ((8 * yuv_to_rgb_inst0.Y_ext) + (16 * yuv_to_rgb_inst0.U_ext));
    yuv_to_rgb_inst0.R_out = (yuv_to_rgb_inst0.R_ext[15]?0:((yuv_to_rgb_inst0.R_ext.range(14, 11) != 0)?255:(yuv_to_rgb_inst0.R_ext[2]?((yuv_to_rgb_inst0.R_ext.range(10, 3) == 255)?255:(yuv_to_rgb_inst0.R_ext.range(10, 3) + 1)):yuv_to_rgb_inst0.R_ext.range(10, 3))));
    yuv_to_rgb_inst0.G_out = (yuv_to_rgb_inst0.G_ext[15]?0:((yuv_to_rgb_inst0.G_ext.range(14, 11) != 0)?255:(yuv_to_rgb_inst0.G_ext[2]?((yuv_to_rgb_inst0.G_ext.range(10, 3) == 255)?255:(yuv_to_rgb_inst0.G_ext.range(10, 3) + 1)):yuv_to_rgb_inst0.G_ext.range(10, 3))));
    yuv_to_rgb_inst0.B_out = (yuv_to_rgb_inst0.B_ext[15]?0:((yuv_to_rgb_inst0.B_ext.range(14, 11) != 0)?255:(yuv_to_rgb_inst0.B_ext[2]?((yuv_to_rgb_inst0.B_ext.range(10, 3) == 255)?255:(yuv_to_rgb_inst0.B_ext.range(10, 3) + 1)):yuv_to_rgb_inst0.B_ext.range(10, 3))));
    rgb_out = (yuv_to_rgb_inst0.R_out, yuv_to_rgb_inst0.G_out, yuv_to_rgb_inst0.B_out);
}

void CTE::compute_not_reset() {
    if (verbose)
        std::cout << "compute : " << "not reset" << std::endl;
    yuv_to_rgb_inst0.reg_U_next = ((yuv_to_rgb_inst0.state == yuv_to_rgb_inst0.S_U)?yuv_in:yuv_to_rgb_inst0.reg_U);
    yuv_to_rgb_inst0.reg_Y1_next = ((yuv_to_rgb_inst0.state == yuv_to_rgb_inst0.S_Y1)?yuv_in:yuv_to_rgb_inst0.reg_Y1);
    yuv_to_rgb_inst0.reg_V_next = ((yuv_to_rgb_inst0.state == yuv_to_rgb_inst0.S_V)?yuv_in:yuv_to_rgb_inst0.reg_V);
    yuv_to_rgb_inst0.reg_Y2_next = ((yuv_to_rgb_inst0.state == yuv_to_rgb_inst0.S_Y2)?yuv_in:yuv_to_rgb_inst0.reg_Y2);
    if (!in_en)
        yuv_to_rgb_inst0.reg_V = 0; 
    else 
        yuv_to_rgb_inst0.reg_V = yuv_to_rgb_inst0.reg_V_next;
    if (!in_en)
        yuv_to_rgb_inst0.reg_U = 0;
    else
        yuv_to_rgb_inst0.reg_U = yuv_to_rgb_inst0.reg_U_next;
    if (!in_en)
        yuv_to_rgb_inst0.reg_Y1 = 0;
    else
        yuv_to_rgb_inst0.reg_Y1 = yuv_to_rgb_inst0.reg_Y1_next;
    if (!in_en)
        yuv_to_rgb_inst0.reg_Y2 = 0;
    else
        yuv_to_rgb_inst0.reg_Y2 = yuv_to_rgb_inst0.reg_Y2_next;
    yuv_to_rgb_inst0.state_next = ((yuv_to_rgb_inst0.state == yuv_to_rgb_inst0.S_U)?yuv_to_rgb_inst0.S_Y1:((yuv_to_rgb_inst0.state == yuv_to_rgb_inst0.S_Y1)?yuv_to_rgb_inst0.S_V:((yuv_to_rgb_inst0.state == yuv_to_rgb_inst0.S_V)?yuv_to_rgb_inst0.S_BUSY1:((yuv_to_rgb_inst0.state == yuv_to_rgb_inst0.S_BUSY1)?yuv_to_rgb_inst0.S_Y2:((yuv_to_rgb_inst0.state == yuv_to_rgb_inst0.S_Y2)?yuv_to_rgb_inst0.S_BUSY2:((yuv_to_rgb_inst0.state == yuv_to_rgb_inst0.S_BUSY2)?yuv_to_rgb_inst0.S_U:yuv_to_rgb_inst0.state))))));
    yuv_to_rgb_inst0.state = ((!in_en)?yuv_to_rgb_inst0.S_U:yuv_to_rgb_inst0.state_next);
    yuv_out = 0;
    yuv_to_rgb_busy = ((yuv_to_rgb_inst0.state == yuv_to_rgb_inst0.S_BUSY1) || (yuv_to_rgb_inst0.state == yuv_to_rgb_inst0.S_BUSY2));
    yuv_to_rgb_out_valid = ((yuv_to_rgb_inst0.state == yuv_to_rgb_inst0.S_BUSY1) || (yuv_to_rgb_inst0.state == yuv_to_rgb_inst0.S_BUSY2));
    out_valid = ((!op_mode)?yuv_to_rgb_out_valid:0);
    busy = ((!op_mode)?yuv_to_rgb_busy:1);
    yuv_to_rgb_inst0.U_ext = (((yuv_to_rgb_inst0.reg_U[7]), (yuv_to_rgb_inst0.reg_U[7]), (yuv_to_rgb_inst0.reg_U[7]), (yuv_to_rgb_inst0.reg_U[7]), (yuv_to_rgb_inst0.reg_U[7]), (yuv_to_rgb_inst0.reg_U[7]), (yuv_to_rgb_inst0.reg_U[7]), (yuv_to_rgb_inst0.reg_U[7])), yuv_to_rgb_inst0.reg_U);
    yuv_to_rgb_inst0.Y_ext = ((yuv_to_rgb_inst0.state == yuv_to_rgb_inst0.S_BUSY1)?(0, yuv_to_rgb_inst0.reg_Y1):(0, yuv_to_rgb_inst0.reg_Y2));
    yuv_to_rgb_inst0.V_ext = (((yuv_to_rgb_inst0.reg_V[7]), (yuv_to_rgb_inst0.reg_V[7]), (yuv_to_rgb_inst0.reg_V[7]), (yuv_to_rgb_inst0.reg_V[7]), (yuv_to_rgb_inst0.reg_V[7]), (yuv_to_rgb_inst0.reg_V[7]), (yuv_to_rgb_inst0.reg_V[7]), (yuv_to_rgb_inst0.reg_V[7])), yuv_to_rgb_inst0.reg_V);
    yuv_to_rgb_inst0.R_ext = ((8 * yuv_to_rgb_inst0.Y_ext) + (13 * yuv_to_rgb_inst0.V_ext));
    yuv_to_rgb_inst0.G_ext = (((8 * yuv_to_rgb_inst0.Y_ext) + (65534 * yuv_to_rgb_inst0.U_ext)) + (65530 * yuv_to_rgb_inst0.V_ext));
    yuv_to_rgb_inst0.B_ext = ((8 * yuv_to_rgb_inst0.Y_ext) + (16 * yuv_to_rgb_inst0.U_ext));
    yuv_to_rgb_inst0.R_out = (yuv_to_rgb_inst0.R_ext[15]?0:((yuv_to_rgb_inst0.R_ext.range(14, 11) != 0)?255:(yuv_to_rgb_inst0.R_ext[2]?((yuv_to_rgb_inst0.R_ext.range(10, 3) == 255)?255:(yuv_to_rgb_inst0.R_ext.range(10, 3) + 1)):yuv_to_rgb_inst0.R_ext.range(10, 3))));
    yuv_to_rgb_inst0.G_out = (yuv_to_rgb_inst0.G_ext[15]?0:((yuv_to_rgb_inst0.G_ext.range(14, 11) != 0)?255:(yuv_to_rgb_inst0.G_ext[2]?((yuv_to_rgb_inst0.G_ext.range(10, 3) == 255)?255:(yuv_to_rgb_inst0.G_ext.range(10, 3) + 1)):yuv_to_rgb_inst0.G_ext.range(10, 3))));
    yuv_to_rgb_inst0.B_out = (yuv_to_rgb_inst0.B_ext[15]?0:((yuv_to_rgb_inst0.B_ext.range(14, 11) != 0)?255:(yuv_to_rgb_inst0.B_ext[2]?((yuv_to_rgb_inst0.B_ext.range(10, 3) == 255)?255:(yuv_to_rgb_inst0.B_ext.range(10, 3) + 1)):yuv_to_rgb_inst0.B_ext.range(10, 3))));
    rgb_out = (yuv_to_rgb_inst0.R_out, yuv_to_rgb_inst0.G_out, yuv_to_rgb_inst0.B_out);
}

void CTE::compute_not_reset_and_in_en() {
    if (verbose)
        std::cout << "compute : " << "not reset and in_en" << std::endl;
    reset = 0;
    in_en = 1;
    yuv_to_rgb_inst0.reg_U_next = ((yuv_to_rgb_inst0.state == yuv_to_rgb_inst0.S_U)?yuv_in:yuv_to_rgb_inst0.reg_U);
    yuv_to_rgb_inst0.reg_Y1_next = ((yuv_to_rgb_inst0.state == yuv_to_rgb_inst0.S_Y1)?yuv_in:yuv_to_rgb_inst0.reg_Y1);
    yuv_to_rgb_inst0.reg_V_next = ((yuv_to_rgb_inst0.state == yuv_to_rgb_inst0.S_V)?yuv_in:yuv_to_rgb_inst0.reg_V);
    yuv_to_rgb_inst0.reg_Y2_next = ((yuv_to_rgb_inst0.state == yuv_to_rgb_inst0.S_Y2)?yuv_in:yuv_to_rgb_inst0.reg_Y2);
    yuv_to_rgb_inst0.reg_V = yuv_to_rgb_inst0.reg_V_next;
    yuv_to_rgb_inst0.reg_U = yuv_to_rgb_inst0.reg_U_next;
    yuv_to_rgb_inst0.reg_Y1 = yuv_to_rgb_inst0.reg_Y1_next;
    yuv_to_rgb_inst0.reg_Y2 = yuv_to_rgb_inst0.reg_Y2_next;
    yuv_to_rgb_inst0.state_next = ((yuv_to_rgb_inst0.state == yuv_to_rgb_inst0.S_U)?yuv_to_rgb_inst0.S_Y1:((yuv_to_rgb_inst0.state == yuv_to_rgb_inst0.S_Y1)?yuv_to_rgb_inst0.S_V:((yuv_to_rgb_inst0.state == yuv_to_rgb_inst0.S_V)?yuv_to_rgb_inst0.S_BUSY1:((yuv_to_rgb_inst0.state == yuv_to_rgb_inst0.S_BUSY1)?yuv_to_rgb_inst0.S_Y2:((yuv_to_rgb_inst0.state == yuv_to_rgb_inst0.S_Y2)?yuv_to_rgb_inst0.S_BUSY2:((yuv_to_rgb_inst0.state == yuv_to_rgb_inst0.S_BUSY2)?yuv_to_rgb_inst0.S_U:yuv_to_rgb_inst0.state))))));
    yuv_to_rgb_inst0.state = yuv_to_rgb_inst0.state_next;
    yuv_out = 0;
    yuv_to_rgb_busy = ((yuv_to_rgb_inst0.state == yuv_to_rgb_inst0.S_BUSY1) || (yuv_to_rgb_inst0.state == yuv_to_rgb_inst0.S_BUSY2));
    yuv_to_rgb_out_valid = ((yuv_to_rgb_inst0.state == yuv_to_rgb_inst0.S_BUSY1) || (yuv_to_rgb_inst0.state == yuv_to_rgb_inst0.S_BUSY2));
    out_valid = ((!op_mode)?yuv_to_rgb_out_valid:0);
    busy = ((!op_mode)?yuv_to_rgb_busy:1);
    yuv_to_rgb_inst0.U_ext = (((yuv_to_rgb_inst0.reg_U[7]), (yuv_to_rgb_inst0.reg_U[7]), (yuv_to_rgb_inst0.reg_U[7]), (yuv_to_rgb_inst0.reg_U[7]), (yuv_to_rgb_inst0.reg_U[7]), (yuv_to_rgb_inst0.reg_U[7]), (yuv_to_rgb_inst0.reg_U[7]), (yuv_to_rgb_inst0.reg_U[7])), yuv_to_rgb_inst0.reg_U);
    yuv_to_rgb_inst0.Y_ext = ((yuv_to_rgb_inst0.state == yuv_to_rgb_inst0.S_BUSY1)?(0, yuv_to_rgb_inst0.reg_Y1):(0, yuv_to_rgb_inst0.reg_Y2));
    yuv_to_rgb_inst0.V_ext = (((yuv_to_rgb_inst0.reg_V[7]), (yuv_to_rgb_inst0.reg_V[7]), (yuv_to_rgb_inst0.reg_V[7]), (yuv_to_rgb_inst0.reg_V[7]), (yuv_to_rgb_inst0.reg_V[7]), (yuv_to_rgb_inst0.reg_V[7]), (yuv_to_rgb_inst0.reg_V[7]), (yuv_to_rgb_inst0.reg_V[7])), yuv_to_rgb_inst0.reg_V);
    yuv_to_rgb_inst0.R_ext = ((8 * yuv_to_rgb_inst0.Y_ext) + (13 * yuv_to_rgb_inst0.V_ext));
    yuv_to_rgb_inst0.G_ext = (((8 * yuv_to_rgb_inst0.Y_ext) + (65534 * yuv_to_rgb_inst0.U_ext)) + (65530 * yuv_to_rgb_inst0.V_ext));
    yuv_to_rgb_inst0.B_ext = ((8 * yuv_to_rgb_inst0.Y_ext) + (16 * yuv_to_rgb_inst0.U_ext));
    yuv_to_rgb_inst0.R_out = (yuv_to_rgb_inst0.R_ext[15]?0:((yuv_to_rgb_inst0.R_ext.range(14, 11) != 0)?255:(yuv_to_rgb_inst0.R_ext[2]?((yuv_to_rgb_inst0.R_ext.range(10, 3) == 255)?255:(yuv_to_rgb_inst0.R_ext.range(10, 3) + 1)):yuv_to_rgb_inst0.R_ext.range(10, 3))));
    yuv_to_rgb_inst0.G_out = (yuv_to_rgb_inst0.G_ext[15]?0:((yuv_to_rgb_inst0.G_ext.range(14, 11) != 0)?255:(yuv_to_rgb_inst0.G_ext[2]?((yuv_to_rgb_inst0.G_ext.range(10, 3) == 255)?255:(yuv_to_rgb_inst0.G_ext.range(10, 3) + 1)):yuv_to_rgb_inst0.G_ext.range(10, 3))));
    yuv_to_rgb_inst0.B_out = (yuv_to_rgb_inst0.B_ext[15]?0:((yuv_to_rgb_inst0.B_ext.range(14, 11) != 0)?255:(yuv_to_rgb_inst0.B_ext[2]?((yuv_to_rgb_inst0.B_ext.range(10, 3) == 255)?255:(yuv_to_rgb_inst0.B_ext.range(10, 3) + 1)):yuv_to_rgb_inst0.B_ext.range(10, 3))));
    rgb_out = (yuv_to_rgb_inst0.R_out, yuv_to_rgb_inst0.G_out, yuv_to_rgb_inst0.B_out);
}

void CTE::compute_all() {
    yuv_to_rgb_inst0.reg_U_next = ((yuv_to_rgb_inst0.state == yuv_to_rgb_inst0.S_U)?yuv_in:yuv_to_rgb_inst0.reg_U);
    yuv_to_rgb_inst0.reg_Y1_next = ((yuv_to_rgb_inst0.state == yuv_to_rgb_inst0.S_Y1)?yuv_in:yuv_to_rgb_inst0.reg_Y1);
    yuv_to_rgb_inst0.reg_V_next = ((yuv_to_rgb_inst0.state == yuv_to_rgb_inst0.S_V)?yuv_in:yuv_to_rgb_inst0.reg_V);
    yuv_to_rgb_inst0.reg_Y2_next = ((yuv_to_rgb_inst0.state == yuv_to_rgb_inst0.S_Y2)?yuv_in:yuv_to_rgb_inst0.reg_Y2);
    if (reset || (!in_en))
        yuv_to_rgb_inst0.reg_V = 0; 
    else 
        yuv_to_rgb_inst0.reg_V = yuv_to_rgb_inst0.reg_V_next;
    if (reset || (!in_en))
        yuv_to_rgb_inst0.reg_U = 0;
    else
        yuv_to_rgb_inst0.reg_U = yuv_to_rgb_inst0.reg_U_next;
    if (reset || (!in_en))
        yuv_to_rgb_inst0.reg_Y1 = 0;
    else
        yuv_to_rgb_inst0.reg_Y1 = yuv_to_rgb_inst0.reg_Y1_next;
    if (reset || (!in_en))
        yuv_to_rgb_inst0.reg_Y2 = 0;
    else
        yuv_to_rgb_inst0.reg_Y2 = yuv_to_rgb_inst0.reg_Y2_next;
    yuv_to_rgb_inst0.state_next = ((yuv_to_rgb_inst0.state == yuv_to_rgb_inst0.S_U)?yuv_to_rgb_inst0.S_Y1:((yuv_to_rgb_inst0.state == yuv_to_rgb_inst0.S_Y1)?yuv_to_rgb_inst0.S_V:((yuv_to_rgb_inst0.state == yuv_to_rgb_inst0.S_V)?yuv_to_rgb_inst0.S_BUSY1:((yuv_to_rgb_inst0.state == yuv_to_rgb_inst0.S_BUSY1)?yuv_to_rgb_inst0.S_Y2:((yuv_to_rgb_inst0.state == yuv_to_rgb_inst0.S_Y2)?yuv_to_rgb_inst0.S_BUSY2:((yuv_to_rgb_inst0.state == yuv_to_rgb_inst0.S_BUSY2)?yuv_to_rgb_inst0.S_U:yuv_to_rgb_inst0.state))))));
    yuv_to_rgb_inst0.state = ((reset || (!in_en))?yuv_to_rgb_inst0.S_U:yuv_to_rgb_inst0.state_next);
    yuv_out = 0;
    yuv_to_rgb_busy = ((yuv_to_rgb_inst0.state == yuv_to_rgb_inst0.S_BUSY1) || (yuv_to_rgb_inst0.state == yuv_to_rgb_inst0.S_BUSY2));
    yuv_to_rgb_out_valid = ((yuv_to_rgb_inst0.state == yuv_to_rgb_inst0.S_BUSY1) || (yuv_to_rgb_inst0.state == yuv_to_rgb_inst0.S_BUSY2));
    out_valid = ((!op_mode)?yuv_to_rgb_out_valid:0);
    busy = ((!op_mode)?yuv_to_rgb_busy:1);
    yuv_to_rgb_inst0.U_ext = (((yuv_to_rgb_inst0.reg_U[7]), (yuv_to_rgb_inst0.reg_U[7]), (yuv_to_rgb_inst0.reg_U[7]), (yuv_to_rgb_inst0.reg_U[7]), (yuv_to_rgb_inst0.reg_U[7]), (yuv_to_rgb_inst0.reg_U[7]), (yuv_to_rgb_inst0.reg_U[7]), (yuv_to_rgb_inst0.reg_U[7])), yuv_to_rgb_inst0.reg_U);
    yuv_to_rgb_inst0.Y_ext = ((yuv_to_rgb_inst0.state == yuv_to_rgb_inst0.S_BUSY1)?(0, yuv_to_rgb_inst0.reg_Y1):(0, yuv_to_rgb_inst0.reg_Y2));
    yuv_to_rgb_inst0.V_ext = (((yuv_to_rgb_inst0.reg_V[7]), (yuv_to_rgb_inst0.reg_V[7]), (yuv_to_rgb_inst0.reg_V[7]), (yuv_to_rgb_inst0.reg_V[7]), (yuv_to_rgb_inst0.reg_V[7]), (yuv_to_rgb_inst0.reg_V[7]), (yuv_to_rgb_inst0.reg_V[7]), (yuv_to_rgb_inst0.reg_V[7])), yuv_to_rgb_inst0.reg_V);
    yuv_to_rgb_inst0.R_ext = ((8 * yuv_to_rgb_inst0.Y_ext) + (13 * yuv_to_rgb_inst0.V_ext));
    yuv_to_rgb_inst0.G_ext = (((8 * yuv_to_rgb_inst0.Y_ext) + (65534 * yuv_to_rgb_inst0.U_ext)) + (65530 * yuv_to_rgb_inst0.V_ext));
    yuv_to_rgb_inst0.B_ext = ((8 * yuv_to_rgb_inst0.Y_ext) + (16 * yuv_to_rgb_inst0.U_ext));
    yuv_to_rgb_inst0.R_out = (yuv_to_rgb_inst0.R_ext[15]?0:((yuv_to_rgb_inst0.R_ext.range(14, 11) != 0)?255:(yuv_to_rgb_inst0.R_ext[2]?((yuv_to_rgb_inst0.R_ext.range(10, 3) == 255)?255:(yuv_to_rgb_inst0.R_ext.range(10, 3) + 1)):yuv_to_rgb_inst0.R_ext.range(10, 3))));
    yuv_to_rgb_inst0.G_out = (yuv_to_rgb_inst0.G_ext[15]?0:((yuv_to_rgb_inst0.G_ext.range(14, 11) != 0)?255:(yuv_to_rgb_inst0.G_ext[2]?((yuv_to_rgb_inst0.G_ext.range(10, 3) == 255)?255:(yuv_to_rgb_inst0.G_ext.range(10, 3) + 1)):yuv_to_rgb_inst0.G_ext.range(10, 3))));
    yuv_to_rgb_inst0.B_out = (yuv_to_rgb_inst0.B_ext[15]?0:((yuv_to_rgb_inst0.B_ext.range(14, 11) != 0)?255:(yuv_to_rgb_inst0.B_ext[2]?((yuv_to_rgb_inst0.B_ext.range(10, 3) == 255)?255:(yuv_to_rgb_inst0.B_ext.range(10, 3) + 1)):yuv_to_rgb_inst0.B_ext.range(10, 3))));
    rgb_out = (yuv_to_rgb_inst0.R_out, yuv_to_rgb_inst0.G_out, yuv_to_rgb_inst0.B_out);
}

#if 0
// reset
void CTE::compute_reset() {

}

// !reset
void CTE::compute_not_reset() {
}

// !reset && in_en
void CTE::compute_not_reset_and_in_en {
}
#endif



// Function calls
void CTE::func_number_0() {
    yuv_to_rgb_inst0.state_next = ((yuv_to_rgb_inst0.state == yuv_to_rgb_inst0.S_U)?yuv_to_rgb_inst0.S_Y1:((yuv_to_rgb_inst0.state == yuv_to_rgb_inst0.S_Y1)?yuv_to_rgb_inst0.S_V:((yuv_to_rgb_inst0.state == yuv_to_rgb_inst0.S_V)?yuv_to_rgb_inst0.S_BUSY1:((yuv_to_rgb_inst0.state == yuv_to_rgb_inst0.S_BUSY1)?yuv_to_rgb_inst0.S_Y2:((yuv_to_rgb_inst0.state == yuv_to_rgb_inst0.S_Y2)?yuv_to_rgb_inst0.S_BUSY2:((yuv_to_rgb_inst0.state == yuv_to_rgb_inst0.S_BUSY2)?yuv_to_rgb_inst0.S_U:yuv_to_rgb_inst0.state))))));
}

void CTE::func_number_1() {
    if (reset || (!in_en))
        yuv_to_rgb_inst0.reg_U = 0;
    else
        yuv_to_rgb_inst0.reg_U = yuv_to_rgb_inst0.reg_U_next;
}

void CTE::func_number_2() {
    if (reset || (!in_en))
        yuv_to_rgb_inst0.reg_V = 0; 
    else 
        yuv_to_rgb_inst0.reg_V = yuv_to_rgb_inst0.reg_V_next;
}

void CTE::func_number_3() {
    if (reset || (!in_en))
        yuv_to_rgb_inst0.reg_Y1 = 0;
    else
        yuv_to_rgb_inst0.reg_Y1 = yuv_to_rgb_inst0.reg_Y1_next;
}

void CTE::func_number_4() {
    if (reset || (!in_en))
        yuv_to_rgb_inst0.reg_Y2 = 0;
    else
        yuv_to_rgb_inst0.reg_Y2 = yuv_to_rgb_inst0.reg_Y2_next;
}

void CTE::func_number_5() {
    yuv_to_rgb_inst0.state = ((reset || (!in_en))?yuv_to_rgb_inst0.S_U:yuv_to_rgb_inst0.state_next);
}

void CTE::func_number_6() {
    busy = ((!op_mode)?yuv_to_rgb_busy:1);
}

void CTE::func_number_7() {
    out_valid = ((!op_mode)?yuv_to_rgb_out_valid:0);
}

void CTE::func_number_8() {
    yuv_out = 0;
}

void CTE::func_number_9() {
    yuv_to_rgb_busy = ((yuv_to_rgb_inst0.state == yuv_to_rgb_inst0.S_BUSY1) || (yuv_to_rgb_inst0.state == yuv_to_rgb_inst0.S_BUSY2));
}

void CTE::func_number_10() {
    yuv_to_rgb_out_valid = ((yuv_to_rgb_inst0.state == yuv_to_rgb_inst0.S_BUSY1) || (yuv_to_rgb_inst0.state == yuv_to_rgb_inst0.S_BUSY2));
}

void CTE::func_number_11() {
    yuv_to_rgb_inst0.reg_U_next = ((yuv_to_rgb_inst0.state == yuv_to_rgb_inst0.S_U)?yuv_in:yuv_to_rgb_inst0.reg_U);
}

void CTE::func_number_12() {
    yuv_to_rgb_inst0.reg_Y1_next = ((yuv_to_rgb_inst0.state == yuv_to_rgb_inst0.S_Y1)?yuv_in:yuv_to_rgb_inst0.reg_Y1);
}

void CTE::func_number_13() {
    yuv_to_rgb_inst0.reg_V_next = ((yuv_to_rgb_inst0.state == yuv_to_rgb_inst0.S_V)?yuv_in:yuv_to_rgb_inst0.reg_V);
}

void CTE::func_number_14() {
    yuv_to_rgb_inst0.reg_Y2_next = ((yuv_to_rgb_inst0.state == yuv_to_rgb_inst0.S_Y2)?yuv_in:yuv_to_rgb_inst0.reg_Y2);
}

void CTE::func_number_15() {
    yuv_to_rgb_inst0.U_ext = (((yuv_to_rgb_inst0.reg_U[7]), (yuv_to_rgb_inst0.reg_U[7]), (yuv_to_rgb_inst0.reg_U[7]), (yuv_to_rgb_inst0.reg_U[7]), (yuv_to_rgb_inst0.reg_U[7]), (yuv_to_rgb_inst0.reg_U[7]), (yuv_to_rgb_inst0.reg_U[7]), (yuv_to_rgb_inst0.reg_U[7])), yuv_to_rgb_inst0.reg_U);
}

void CTE::func_number_16() {
    yuv_to_rgb_inst0.Y_ext = ((yuv_to_rgb_inst0.state == yuv_to_rgb_inst0.S_BUSY1)?(0, yuv_to_rgb_inst0.reg_Y1):(0, yuv_to_rgb_inst0.reg_Y2));
}

void CTE::func_number_17() {
    yuv_to_rgb_inst0.V_ext = (((yuv_to_rgb_inst0.reg_V[7]), (yuv_to_rgb_inst0.reg_V[7]), (yuv_to_rgb_inst0.reg_V[7]), (yuv_to_rgb_inst0.reg_V[7]), (yuv_to_rgb_inst0.reg_V[7]), (yuv_to_rgb_inst0.reg_V[7]), (yuv_to_rgb_inst0.reg_V[7]), (yuv_to_rgb_inst0.reg_V[7])), yuv_to_rgb_inst0.reg_V);
}

void CTE::func_number_18() {
    yuv_to_rgb_inst0.R_ext = ((8 * yuv_to_rgb_inst0.Y_ext) + (13 * yuv_to_rgb_inst0.V_ext));
}

void CTE::func_number_19() {
    yuv_to_rgb_inst0.G_ext = (((8 * yuv_to_rgb_inst0.Y_ext) + (65534 * yuv_to_rgb_inst0.U_ext)) + (65530 * yuv_to_rgb_inst0.V_ext));
}

void CTE::func_number_20() {
    yuv_to_rgb_inst0.B_ext = ((8 * yuv_to_rgb_inst0.Y_ext) + (16 * yuv_to_rgb_inst0.U_ext));
}

void CTE::func_number_21() {
    yuv_to_rgb_inst0.R_out = (yuv_to_rgb_inst0.R_ext[15]?0:((yuv_to_rgb_inst0.R_ext.range(14, 11) != 0)?255:(yuv_to_rgb_inst0.R_ext[2]?((yuv_to_rgb_inst0.R_ext.range(10, 3) == 255)?255:(yuv_to_rgb_inst0.R_ext.range(10, 3) + 1)):yuv_to_rgb_inst0.R_ext.range(10, 3))));
}

void CTE::func_number_22() {
    yuv_to_rgb_inst0.G_out = (yuv_to_rgb_inst0.G_ext[15]?0:((yuv_to_rgb_inst0.G_ext.range(14, 11) != 0)?255:(yuv_to_rgb_inst0.G_ext[2]?((yuv_to_rgb_inst0.G_ext.range(10, 3) == 255)?255:(yuv_to_rgb_inst0.G_ext.range(10, 3) + 1)):yuv_to_rgb_inst0.G_ext.range(10, 3))));
}

void CTE::func_number_23() {
    yuv_to_rgb_inst0.B_out = (yuv_to_rgb_inst0.B_ext[15]?0:((yuv_to_rgb_inst0.B_ext.range(14, 11) != 0)?255:(yuv_to_rgb_inst0.B_ext[2]?((yuv_to_rgb_inst0.B_ext.range(10, 3) == 255)?255:(yuv_to_rgb_inst0.B_ext.range(10, 3) + 1)):yuv_to_rgb_inst0.B_ext.range(10, 3))));
}

void CTE::func_number_24() {
    rgb_out = (yuv_to_rgb_inst0.R_out, yuv_to_rgb_inst0.G_out, yuv_to_rgb_inst0.B_out);
}


