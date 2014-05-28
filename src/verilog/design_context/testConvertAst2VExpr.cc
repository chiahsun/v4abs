#include "test/UnitTest.h" 
#include "verilog/vast/AstParser.h"
#include "ConvertAst2VExpr.h"


void test_convert_unsigned_number() {
    AstUnsignedNumberParser parser;
    AstUnsignedNumberHandle pAstUnsignedNumber = parser.parseString("(unsigned_number 121)");
    VExprUnsignedNumberHandle pUnsignedNumber = ConvertAst2VExpr::convert(pAstUnsignedNumber);
    assertEqual("121", pUnsignedNumber->getString(), "Test convert unsigned number");
    UNIT_TEST_FUNCTION_END_FUNCTION_TEST();
}

void test_convert_binary_number() {
    AstBinaryNumberParser parser;
    AstBinaryNumberHandle pAstBinaryNumber = parser.parseString("(binary_number 2'b11)");

    VExprBinaryNumberHandle pBinaryNumber = ConvertAst2VExpr::convert(pAstBinaryNumber);
    assertEqual("2'b11", pBinaryNumber->getString(), "Test convert binary number");
    UNIT_TEST_FUNCTION_END_FUNCTION_TEST();
}

void test_convert_octal_number() {
    AstOctalNumberParser parser;
    AstOctalNumberHandle pAstOctalNumber = parser.parseString("(octal_number 3'o2)");

    VExprOctalNumberHandle pOctalNumber = ConvertAst2VExpr::convert(pAstOctalNumber);
    assertEqual("3'o2", pOctalNumber->getString(), "Test convert octal number");
    UNIT_TEST_FUNCTION_END_FUNCTION_TEST();
}

void test_convert_decimal_number() {
    AstDecimalNumberParser parser;
    AstDecimalNumberHandle pAstDecimalNumber = parser.parseString("(decimal_number 20'd921)");
    
    VExprDecimalNumberHandle pDecimalNumber = ConvertAst2VExpr::convert(pAstDecimalNumber);
    assertEqual("20'd921", pDecimalNumber->getString(), "Test convert decimal number");
    UNIT_TEST_FUNCTION_END_FUNCTION_TEST();
}

void test_convert_hex_number() {
    AstHeximalNumberParser parser;
    AstHeximalNumberHandle pAstHexNumber = parser.parseString("(heximal_number 16'hffff)");

    VExprHexNumberHandle pHexNumber = ConvertAst2VExpr::convert(pAstHexNumber);
    assertEqual("16'hffff", pHexNumber->getString(), "Test convert hex number");

    UNIT_TEST_FUNCTION_END_FUNCTION_TEST();
}

void test_convert_number_unsigned_number() {
    AstNumberParser parser;
    AstNumberHandle pAstNumber = parser.parseString("(number (unsigned_number 123))");

    VExprNumberHandle pNumber = ConvertAst2VExpr::convert(pAstNumber);
    assertEqual("123", pNumber->getString(), "Test convert number unsigned number");

    UNIT_TEST_FUNCTION_END_FUNCTION_TEST();
}

void test_convert_simple_identifier() {
    AstSimpleIdentifierParser parser;
    AstSimpleIdentifierHandle pAstSimpleIdentifier = parser.parseString("(simple_identifier reg_a)");

    VExprSingleIdentifierHandle pSingleIdentifier = ConvertAst2VExpr::convert(pAstSimpleIdentifier);
    assertEqual("reg_a", pSingleIdentifier->getString(), "Test convert simple identifier");

    UNIT_TEST_FUNCTION_END_FUNCTION_TEST();
}

void test_convert_multi_identifier() {
    AstMultiIdentifierParser parser;
    AstMultiIdentifierHandle pAstMultiIdentifier = parser.parseString("(multi_identifier (single_identifier (simple_identifier A)) . (single_identifier (simple_identifier B)))");

    VExprHierIdentifierHandle pHierIdentifier = ConvertAst2VExpr::convert(pAstMultiIdentifier);
    assertEqual("A.B", pHierIdentifier->getString(), "Test convert multi identifier");

    UNIT_TEST_FUNCTION_END_FUNCTION_TEST();
}

void test_convert_identifier_single_identifier() {
    AstIdentifierParser parser;
    AstIdentifierHandle pAstIdentifier = parser.parseString("(identifier (single_identifier (simple_identifier reg_a)))");

    VExprIdentifierHandle pIdentifier = ConvertAst2VExpr::convert(pAstIdentifier);

    assertEqual("reg_a", pIdentifier->getString(), "Test convert identifier single identifier");
    UNIT_TEST_FUNCTION_END_FUNCTION_TEST();
}

void test_convert_primary_number() {
    AstPrimaryParser parser;
    AstPrimaryHandle pAstPrimary = parser.parseString("(primary (number (unsigned_number 20)))");

    VExprPrimaryHandle pPrimary = ConvertAst2VExpr::convert(pAstPrimary);

    assertEqual("20", pPrimary->getString(), "Test convert primary number");
    UNIT_TEST_FUNCTION_END_FUNCTION_TEST();
}

void test_convert_unary_expression() {
    AstUnaryExpressionParser parser;
    AstUnaryExpressionHandle pAstUnaryExpression = parser.parseString("(unary_expression (unary_operator !) (primary (identifier (single_identifier (simple_identifier abc)))))");

    VExprUnaryHandle pUnary = ConvertAst2VExpr::convert(pAstUnaryExpression);

    assertEqual("!abc", pUnary->getString(), "Test convert unary expression");
    UNIT_TEST_FUNCTION_END_FUNCTION_TEST();
}

void test_convert_expression_unary() {
    AstExpressionParser parser;
    AstExpressionHandle pAstExpression = parser.parseString("(expression (unary_operator !) (primary (identifier (single_identifier (simple_identifier A)))))");

    VExprExpressionHandle pExpression = ConvertAst2VExpr::convert(pAstExpression);

    assertEqual("!A", pExpression->getString(), "Test convert expression unary expression");
    UNIT_TEST_FUNCTION_END_FUNCTION_TEST();
}

void test_convert_binary_expression() {
    AstBinaryExpressionParser parser;
    AstBinaryExpressionHandle pAstBinaryExpression = parser.parseString("(expression (expression (primary (identifier (single_identifier (simple_identifier wire_a))))) + (expression (primary (number (binary_number 2'b11)))))");

    VExprBinaryHandle pBinary = ConvertAst2VExpr::convert(pAstBinaryExpression);

    assertEqual("(wire_a+2'b11)", pBinary->getString(), "Test convert binary expression");
    UNIT_TEST_FUNCTION_END_FUNCTION_TEST();
}

void test_convert_ternary_expression() {
    AstTernaryExpressionParser parser;
    AstTernaryExpressionHandle pAstTernaryExpression = parser.parseString("(expression (expression (primary (number (binary_number 1'b1)))) ? (expression (primary (number (binary_number 2'b00)))) : (expression (primary (number (binary_number 2'b11)))))");
    
    VExprTernaryHandle pTernary = ConvertAst2VExpr::convert(pAstTernaryExpression);

    assertEqual("(1'b1?2'b00:2'b11)", pTernary->getString(), "Test convert ternary expression");
    UNIT_TEST_FUNCTION_END_FUNCTION_TEST();
}

void test_convert_bit_select() {
    AstBitSelectParser parser;
    AstBitSelectHandle pAstBitSelect = parser.parseString("(bit_select [ (expression (primary (number (unsigned_number 2)))) ])");

    VExprBitSelectHandle pBitSelect = ConvertAst2VExpr::convert(pAstBitSelect);

    assertEqual("[2]", pBitSelect->getString(), "Test convert bit select");
    UNIT_TEST_FUNCTION_END_FUNCTION_TEST();
}

void test_convert_range_select() {
    AstRangeSelectParser parser;
    AstRangeSelectHandle pAstRangeSelect = parser.parseString("(range_select [ (expression (primary (number (unsigned_number 2)))) : (expression (primary (number (unsigned_number 2)))) ])");

    VExprRangeSelectHandle pRangeSelect = ConvertAst2VExpr::convert(pAstRangeSelect);
    assertEqual("[2:2]", pRangeSelect->getString(), "Test convert range select");
    UNIT_TEST_FUNCTION_END_FUNCTION_TEST();
}

void test_convert_select() {
    AstSelectParser parser;
    AstSelectHandle pAstSelect = parser.parseString("(select [ (expression (primary (number (unsigned_number 2)))) : (expression (primary (number (unsigned_number 2)))) ])");

    VExprSelectHandle pSelect = ConvertAst2VExpr::convert(pAstSelect);
    assertEqual("[2:2]", pSelect->getString(), "Test convert select");
    UNIT_TEST_FUNCTION_END_FUNCTION_TEST();
}

void test_convert_select_identifier() {
    AstSelectIdentifierParser parser;
    AstSelectIdentifierHandle pAstSelectIdentifier = parser.parseString("(select_identifier (identifier (single_identifier (simple_identifier A))) [ (expression (primary (number (unsigned_number 2)))) ])");

    VExprSelectIdentifierHandle pSelectIdentifier = ConvertAst2VExpr::convert(pAstSelectIdentifier);
    assertEqual("A[2]", pSelectIdentifier->getString(), "Test convert select identifier");
    UNIT_TEST_FUNCTION_END_FUNCTION_TEST();
}

void test_convert_concatenation() {
    AstConcatenationParser parser;
    AstConcatenationHandle pAstConcatenation = parser.parseString("(concatenation { (expression (primary (number (binary_number (2'b11))))) , (expression (primary (number (binary_number 2'b00)))) , (expression (primary (number (binary_number 1'b1)))) })");

    VExprConcatenationHandle pConcatenation = ConvertAst2VExpr::convert(pAstConcatenation);
    assertEqual("{2'b11,2'b00,1'b1}", pConcatenation->getString(), "Test convert concatenation");
    UNIT_TEST_FUNCTION_END_FUNCTION_TEST();
}

void test_convert_multiple_concatenation() {
    AstMultipleConcatenationParser parser;
    AstMultipleConcatenationHandle pAstMultipleConcatenation = parser.parseString("(multiple_concatenation { (expression (primary (number (unsigned_number 4)))) { (expression (primary (number (binary_number 1'b1)))) } })");

    VExprMultipleConcatenationHandle pMultipleConcatenation =
        ConvertAst2VExpr::convert(pAstMultipleConcatenation);

    assertEqual("{4{1'b1}}", pMultipleConcatenation->getString(), "Test convert multiple concatenation");
    UNIT_TEST_FUNCTION_END_FUNCTION_TEST();
}

void test_convert_constant_primary() {
    AstConstantPrimaryParser parser;
    AstConstantPrimaryHandle pAstConstantPrimary = parser.parseString("(constant_primary (identifier (single_identifier (simple_identifier reg_a))))");

    VExprConstantPrimaryHandle pConstantPrimary =
        ConvertAst2VExpr::convert(pAstConstantPrimary);

    assertEqual("reg_a", pConstantPrimary->getString(), "Test convert constant primary");
    UNIT_TEST_FUNCTION_END_FUNCTION_TEST();
}

void test_convert_constant_expression_constant_primary() {
    AstConstantExpressionParser parser;
    AstConstantExpressionHandle pAstConstantExpression = parser.parseString("(constant_expression (constant_primary (identifier (single_identifier (simple_identifier reg_a)))))");

    VExprConstantExpressionHandle pConstantExpression =
        ConvertAst2VExpr::convert(pAstConstantExpression);

    assertEqual("reg_a", pConstantExpression->getString(), "Test convert constant expression constant primary");
    UNIT_TEST_FUNCTION_END_FUNCTION_TEST();
}

void test_convert_range() {
    AstRangeParser parser;
    AstRangeHandle pAstRange = parser.parseString("(range [ (constant_expression (constant_primary (number (unsigned_number 5)))) : (constant_expression (constant_primary (number (unsigned_number 2)))) ])");

    VExprRangeHandle pRange = 
        ConvertAst2VExpr::convert(pAstRange);
    assertEqual("[5:2]", pRange->getString(), "Test convert range");
    UNIT_TEST_FUNCTION_END_FUNCTION_TEST();
}


void test_convert_net_lvalue() {
    AstNetLvalueParser parser;
    AstNetLvalueHandle pAstNetLvalue = parser.parseString("(net_lvalue (identifier (single_identifier (simple_identifier A))))");

    VExprNetLvalueHandle pNetLvalue =
        ConvertAst2VExpr::convert(pAstNetLvalue);
    assertEqual("A", pNetLvalue->getString(), "Test convert net lvalue");

    UNIT_TEST_FUNCTION_END_FUNCTION_TEST();
}

void test_convert_net_assignment() {
    AstNetAssignmentParser parser;
    AstNetAssignmentHandle pAstNetAssignment = parser.parseString("(net_assignment (net_lvalue (identifier (single_identifier (simple_identifier debug_B0)))) = (expression (primary (identifier (single_identifier (simple_identifier B))) [ (expression (primary (number (unsigned_number 0)))) ])))");

    VExprNetAssignmentHandle pNetAssignement =
        ConvertAst2VExpr::convert(pAstNetAssignment);
    assertEqual("assign debug_B0=B[0]", pNetAssignement->getString(), "Test convert net assignment");

    UNIT_TEST_FUNCTION_END_FUNCTION_TEST();
}

void test_convert_list_of_net_assignment() {
    AstListOfNetAssignmentsParser parser;
    AstListOfNetAssignmentsHandle pAstListOfNetAssignments = parser.parseString("(list_of_net_assignments (net_assignment (net_lvalue (identifier (single_identifier (simple_identifier reg_a)))) = (expression (primary (number (binary_number 1'b1))))) , (net_assignment (net_lvalue (identifier (single_identifier (simple_identifier reg_b)))) = (expression (primary (number (binary_number 2'b11))))))");

    std::vector<VExprNetAssignmentHandle> vecNetAssignment =
        ConvertAst2VExpr::convert(pAstListOfNetAssignments);
    assertEqual(2, vecNetAssignment.size(), "Test convert list of net assignment");

    UNIT_TEST_FUNCTION_END_FUNCTION_TEST();
}

void test_convert_continuous_assignment() {
    AstContinuousAssignParser parser;
    AstContinuousAssignHandle pAstContinuousAssign = parser.parseString("(continuous_assign (keyword_assign assign ) (list_of_net_assignments (net_assignment (net_lvalue (identifier (single_identifier (simple_identifier debug_B0)))) = (expression (primary (identifier (single_identifier (simple_identifier B))) [ (expression (primary (number (unsigned_number 0)))) ])))) ;)");

    VExprContinuousAssignmentHandle pContinuousAssignment =
        ConvertAst2VExpr::convert(pAstContinuousAssign);
    assertEqual("assign debug_B0=B[0]", pContinuousAssignment->getString(), "Test convert continuous assignment");

    UNIT_TEST_FUNCTION_END_FUNCTION_TEST();
}

void test_convert_register_name() {
    AstRegisterNameParser parser;
    AstRegisterNameHandle pAstRegisterName = parser.parseString("(register_name (identifier (single_identifier (simple_identifier mem_array))) [ (constant_expression (constant_primary (number (unsigned_number 2)))) : (constant_expression (constant_primary (number (unsigned_number 0)))) ])");
    assertEqual("", pAstRegisterName->toString(), "Test ast register name to string");

    UNIT_TEST_FUNCTION_END_FUNCTION_TEST();
}

void test_convert_reg_lvalue() {
    AstRegLvalueParser parser;
    AstRegLvalueHandle pAstRegLvalue = parser.parseString("(reg_lvalue (identifier (single_identifier (simple_identifier reg_a))))");

    VExprRegLvalueHandle pRegLvalue =
        ConvertAst2VExpr::convert(pAstRegLvalue);
    assertEqual("reg_a", pRegLvalue->getString(), "Test convert reg lvalue");
    
    UNIT_TEST_FUNCTION_END_FUNCTION_TEST();
}

void test_convert_blocking_assignment() {
    AstBlockingAssignmentParser parser;
    AstBlockingAssignmentHandle pAstBlockingAssignment = parser.parseString("(blocking_assignment (reg_lvalue (identifier (single_identifier (simple_identifier B))) [ (expression (primary (number (unsigned_number 0)))) ]) = (expression (primary (identifier (single_identifier (simple_identifier packed_B))) [ (expression (primary (number (unsigned_number 15)))) : (expression (primary (number (unsigned_number 0)))) ])))");

    VExprBlockingAssignmentHandle pBlockingAssignment =
        ConvertAst2VExpr::convert(pAstBlockingAssignment);
    assertEqual("B[0] = packed_B[15:0]", pBlockingAssignment->getString(), "Test convert blocking assignment");

    UNIT_TEST_FUNCTION_END_FUNCTION_TEST();
}

void test_convert_non_blocking_assignment() {
    AstNonBlockingAssignmentParser parser;
    AstNonBlockingAssignmentHandle pAstNonBlockingAssignment = parser.parseString("(non_blocking_assignment (reg_lvalue (identifier (single_identifier (simple_identifier B))) [ (expression (primary (number (unsigned_number 0)))) ]) < = (expression (primary (identifier (single_identifier (simple_identifier packed_B))) [ (expression (primary (number (unsigned_number 15)))) : (expression (primary (number (unsigned_number 0)))) ])))");


    VExprNonBlockingAssignmentHandle pNonBlockingAssignment =
        ConvertAst2VExpr::convert(pAstNonBlockingAssignment);

    assertEqual("B[0] <= packed_B[15:0]", pNonBlockingAssignment->getString(), "Test convert non blocking");

    UNIT_TEST_FUNCTION_END_FUNCTION_TEST();
}

void test_convert_statement_blocking_assignment() {
    AstStatementParser parser;
    AstStatementHandle pAstStatement = parser.parseString("(statement (blocking_assignment (reg_lvalue (identifier (single_identifier (simple_identifier A)))) = (expression (primary (identifier (single_identifier (simple_identifier B)))))) ;)");

    VExprStatementHandle pStatement =
        ConvertAst2VExpr::convert(pAstStatement);

    assertEqual("A = B;\n", pStatement->getString(), "Test convert blocking assignment");

    UNIT_TEST_FUNCTION_END_FUNCTION_TEST();
}
    
void test_convert_statement_procedural_continuous_assignment() {
    AstStatementParser parser;
    AstStatementHandle pAstStatement = parser.parseString("(statement (procedural_continuous_assignment (keyword_assign assign ) (reg_assignment (reg_lvalue (identifier (single_identifier (simple_identifier reg_A)))) = (expression (expression (primary (number (binary_number 8'b1001_1101)))) & (expression (primary (identifier (single_identifier (simple_identifier A))) [ (expression (expression (primary (number (unsigned_number 5)))) + (expression (primary (number (unsigned_number 3))))) : (expression (primary (number (unsigned_number 1)))) ])))) ;) ;)");

    VExprStatementHandle pStatement =
        ConvertAst2VExpr::convert(pAstStatement);

    // Here we not print semicolon, its caller's duty to do that
    // Since we have for(reg_assignment; expression, reg_assignment), so we cannot append semicolon automatically
    assertEqual("reg_A = (8'b1001_1101&A[(5+3):1])", pStatement->getString(), "Test convert statement procedural continuous assignment");

    UNIT_TEST_FUNCTION_END_FUNCTION_TEST();
}
    
void test_convert_procedural_timing_control_statement() {
    AstProceduralTimingControlStatementParser parser;
    AstProceduralTimingControlStatementHandle pAstProceduralTimingControlStatement = parser.parseString("(procedural_timing_control_statement (delay_or_event_control (event_control @ ( (event_expression (event_expression (keyword_posedge posedge ) (expression (primary (identifier (single_identifier (simple_identifier clk)))))) (keyword_or  or ) (event_expression (keyword_negedge negedge ) (expression (primary (identifier (single_identifier (simple_identifier reset))))))) ))) (statement_or_null (statement (non_blocking_assignment (reg_lvalue (identifier (single_identifier (simple_identifier state)))) < = (expression (primary (number (unsigned_number 0))))) ;)))");

    VExprEventStatementHandle pEventStatement =
        ConvertAst2VExpr::convert(pAstProceduralTimingControlStatement);

    assertEqual("always @ (posedge clk or negedge reset)\n"
                "  state <= 0;\n", pEventStatement->getString(), "Test convert procedural timing control statement to event statement");

    UNIT_TEST_FUNCTION_END_FUNCTION_TEST();
}

void test_convert_conditional_statement() {
    AstConditionalStatementParser parser;
    AstConditionalStatementHandle pAstConditional = parser.parseString("(conditional_statement (keyword_if if) ( (expression (primary (identifier (single_identifier (simple_identifier rst))))) ) (statement_or_null (statement (non_blocking_assignment (reg_lvalue (identifier (single_identifier (simple_identifier A)))) < = (expression (primary (number (unsigned_number 0))))) ;)) (keyword_else \nelse) (statement_or_null (statement (non_blocking_assignment (reg_lvalue (identifier (single_identifier (simple_identifier A)))) < = (expression (primary (number (unsigned_number 1))))) ;)))");

    VExprConditionalStatementHandle pConditional =
        ConvertAst2VExpr::convert(pAstConditional);

    assertEqual("if (rst) {\n"
                "  A <= 0;\n"
                "} else {\n"
                "  A <= 1;\n"
                "}\n", pConditional->getString(), "Test convert conditional statement");

    UNIT_TEST_FUNCTION_END_FUNCTION_TEST();
}

void test_convert_case_statement() {
    AstCaseStatementParser parser;
    AstCaseStatementHandle pAstCaseStatement = parser.parseString("(case_statement (keyword_case case ) ( (expression (primary (identifier (single_identifier (simple_identifier state))))) ) (case_item (expression (primary (identifier (single_identifier (simple_identifier STATE_BEGIN))))) : (statement_or_null (statement (blocking_assignment (reg_lvalue (identifier (single_identifier (simple_identifier next_state)))) = (expression (primary (identifier (single_identifier (simple_identifier state)))))) ;))) (case_item (expression (primary (identifier (single_identifier (simple_identifier STATE_OUT_ITER))))) : (statement_or_null (statement (blocking_assignment (reg_lvalue (identifier (single_identifier (simple_identifier next_state)))) = (expression (primary (identifier (single_identifier (simple_identifier STATE_OUTPUT)))))) ;))) (keyword_endcase \nendcase\n))");

    VExprCaseStatementHandle pCaseStatement =
        ConvertAst2VExpr::convert(pAstCaseStatement);

    assertEqual("case (state)\n"
                "  STATE_BEGIN:\n"
                "    next_state = state;\n"
                "  STATE_OUT_ITER:\n"
                "    next_state = STATE_OUTPUT;\n"
                "endcase\n", pCaseStatement->getString(), "Test convert case statement");

    UNIT_TEST_FUNCTION_END_FUNCTION_TEST();
}

void test_convert_loop_statement() {
    AstLoopStatementParser parser;
    AstLoopStatementHandle pAstLoopStatement = parser.parseString("(loop_statement (keyword_for for ) ( (reg_assignment (reg_lvalue (identifier (single_identifier (simple_identifier i)))) = (expression (primary (number (unsigned_number 0))))) ; (expression (expression (primary (identifier (single_identifier (simple_identifier i))))) < (expression (primary (number (unsigned_number 16))))) ; (reg_assignment (reg_lvalue (identifier (single_identifier (simple_identifier i)))) = (expression (expression (primary (identifier (single_identifier (simple_identifier i))))) + (expression (primary (number (unsigned_number 1)))))) ) (statement (seq_block (keyword_begin  begin\n) (statement (non_blocking_assignment (reg_lvalue (identifier (single_identifier (simple_identifier X))) [ (expression (primary (identifier (single_identifier (simple_identifier i))))) ]) < = (expression (primary (identifier (single_identifier (simple_identifier next_X))) [ (expression (primary (identifier (single_identifier (simple_identifier i))))) ]))) ;) (keyword_end \nend\n))))");

    VExprLoopStatementHandle pLoopStatement =
        ConvertAst2VExpr::convert(pAstLoopStatement);

    assertEqual("for (i = 0; (i<16); i = (i+1))\n"
                "  begin\n"
                "    X[i] <= next_X[i];\n"
                "  end\n", pLoopStatement->getString(), "Test convert loop statement");

    UNIT_TEST_FUNCTION_END_FUNCTION_TEST();
}
   
void test_convert_input_declaration() {
    AstInputDeclarationParser parser;
    AstInputDeclarationHandle pAstInputDeclaration = parser.parseString("(input_declaration (keyword_input input ) (range [ (constant_expression (constant_primary (number (unsigned_number 2)))) : (constant_expression (constant_primary (number (unsigned_number 0)))) ]) (list_of_port_identifiers (identifier (single_identifier (simple_identifier A))) , (identifier (single_identifier (simple_identifier B)))) ;)");

    VExprInputDeclarationHandle pInputDeclaration =
        ConvertAst2VExpr::convert(pAstInputDeclaration);

    assertEqual("input [2:0] A;\n"
                "input [2:0] B;\n", pInputDeclaration->getString(), "Test convert input declaration");

    UNIT_TEST_FUNCTION_END_FUNCTION_TEST();
}
    
void test_convert_module_instantiation_named() {
    AstModuleInstantiationParser parser;
    AstModuleInstantiationHandle pAstModuleInstantiation = parser.parseString("(module_instantiation (identifier (single_identifier (simple_identifier ADD))) (module_instance (name_of_instance (identifier (single_identifier (simple_identifier add1)))) ( (list_of_module_connections (named_port_connection . (identifier (single_identifier (simple_identifier clk))) ( (expression (primary (identifier (single_identifier (simple_identifier clk))))) )) , (named_port_connection . (identifier (single_identifier (simple_identifier rst))) ( (expression (primary (identifier (single_identifier (simple_identifier rst))))) )) , (named_port_connection . (identifier (single_identifier (simple_identifier A))) ( (expression (primary (identifier (single_identifier (simple_identifier A))))) )) , (named_port_connection . (identifier (single_identifier (simple_identifier B))) ( (expression (primary (identifier (single_identifier (simple_identifier B))))) )) , (named_port_connection . (identifier (single_identifier (simple_identifier O))) ( (expression (primary (identifier (single_identifier (simple_identifier O))))) ))) )) ;)");

    VExprModuleInstantiationHandle pModuleInstantiation =
        ConvertAst2VExpr::convert(pAstModuleInstantiation);

    assertEqual("ADD add1(.rst(rst), .A(A), .B(B), .O(O));\n", pModuleInstantiation->getString(), "Test convert module instantiation named");

    UNIT_TEST_FUNCTION_END_FUNCTION_TEST();
}

void test_convert_module_instantiation_ordered() {
    AstModuleInstantiationParser parser;
    AstModuleInstantiationHandle pAstModuleInstantiation = parser.parseString("(module_instantiation (identifier (single_identifier (simple_identifier ADD))) (module_instance (name_of_instance (identifier (single_identifier (simple_identifier add1)))) ( (list_of_module_connections (ordered_port_connection (expression (primary (identifier (single_identifier (simple_identifier clk)))))) , (ordered_port_connection (expression (primary (identifier (single_identifier (simple_identifier rst)))))) , (ordered_port_connection (expression (primary (identifier (single_identifier (simple_identifier A)))))) , (ordered_port_connection (expression (primary (identifier (single_identifier (simple_identifier B)))))) , (ordered_port_connection (expression (primary (identifier (single_identifier (simple_identifier O))))))) )) ;)");

    VExprModuleInstantiationHandle pModuleInstantiation =
        ConvertAst2VExpr::convert(pAstModuleInstantiation);

    assertEqual("ADD add1(clk, rst, A, B, O);\n", pModuleInstantiation->getString(), "Test convert module instantiation ordered");

    UNIT_TEST_FUNCTION_END_FUNCTION_TEST();
}

void test_convert_always() {
    AstAlwaysConstructParser parser;
    AstAlwaysConstructHandle pAstAlwaysConstruct = parser.parseString("(always_construct (keyword_always always ) (statement (procedural_timing_control_statement (delay_or_event_control (event_control @ ( * ))) (statement_or_null (statement (seq_block (keyword_begin  begin\n) (statement (blocking_assignment (reg_lvalue (identifier (single_identifier (simple_identifier next_state)))) = (expression (primary (identifier (single_identifier (simple_identifier state)))))) ;) (statement (blocking_assignment (reg_lvalue (identifier (single_identifier (simple_identifier next_reg_i)))) = (expression (primary (identifier (single_identifier (simple_identifier reg_i)))))) ;) (keyword_end \nend\n)))))))");

    VExprAlwaysHandle pAlways =
        ConvertAst2VExpr::convert(pAstAlwaysConstruct);

    assertEqual("always always @ (*)\n"
                "  begin\n"
                "    next_state = state;\n"
                "    next_reg_i = reg_i;\n"
                "  end\n", pAlways->getString(), "Test convert always");

    UNIT_TEST_FUNCTION_END_FUNCTION_TEST();
}

int main() {

    test_convert_unsigned_number();
    test_convert_binary_number();
    test_convert_octal_number();
    test_convert_decimal_number();
    test_convert_hex_number();
    test_convert_number_unsigned_number();

    test_convert_simple_identifier();
    test_convert_multi_identifier();
    test_convert_identifier_single_identifier();
    test_convert_primary_number();
    test_convert_unary_expression();

    test_convert_expression_unary();
    test_convert_binary_expression();
    test_convert_ternary_expression();
    test_convert_bit_select();
    test_convert_range_select();
    test_convert_select();
    test_convert_select_identifier();
    test_convert_concatenation();
    test_convert_multiple_concatenation();
    test_convert_constant_primary();
    test_convert_constant_expression_constant_primary();

    test_convert_range();
    test_convert_net_lvalue();
    test_convert_net_assignment();
    test_convert_list_of_net_assignment();
    test_convert_continuous_assignment();

    test_convert_register_name();

    test_convert_reg_lvalue();
    test_convert_blocking_assignment();
    test_convert_non_blocking_assignment();

    test_convert_statement_blocking_assignment();
    test_convert_statement_procedural_continuous_assignment();
    test_convert_procedural_timing_control_statement();

    test_convert_conditional_statement();
    test_convert_case_statement();
    test_convert_loop_statement();

    test_convert_input_declaration();
    test_convert_module_instantiation_named();
    test_convert_module_instantiation_ordered();

    test_convert_always();

    return 0;
}
