import config
import generate_unit_with_name
import generate_composite_with_name
import generate_composite_without_name
import generate_star_without_name
import generate_sequence_without_name
import generate_sequence_with_name
import generate_plus_without_name
import generate_question_without_name
#import generate_question
#import generate_composite_without_name
#import generate_star
#import generate_sequence_with_name
#import generate_plus
#import generate_composite_without_name

def get_parsing_rule_from_first_line(tcl_filename):
    with open(tcl_filename, 'r') as f:
        rule = f.readline()
    return rule[0:len(rule)-1:]

def get_acceptor_from_tcl_file_name(tcl_filename):
    parsing_rule = get_parsing_rule_from_first_line(tcl_filename) 
    if parsing_rule == 'generate_unit_with_name.py':
        return generate_unit_with_name.get_acceptor_from_file(tcl_filename)
    elif parsing_rule == 'generate_composite_with_name.py':
        return generate_composite_with_name.get_acceptor_from_file(tcl_filename) 
    elif parsing_rule == 'generate_composite_without_name.py':
        return generate_composite_without_name.get_acceptor_from_file(tcl_filename) 
    elif parsing_rule == 'generate_star_without_name.py':
        return generate_star_without_name.get_acceptor_from_file(tcl_filename)
    elif parsing_rule == 'generate_sequence_without_name.py':
        return generate_sequence_without_name.get_acceptor_from_file(tcl_filename)
    elif parsing_rule == 'generate_sequence_with_name.py':
        return generate_sequence_with_name.get_acceptor_from_file(tcl_filename)
    elif parsing_rule == 'generate_plus_without_name.py':
        return generate_plus_without_name.get_acceptor_from_file(tcl_filename)
    elif parsing_rule == 'generate_question_without_name.py':
        return generate_question_without_name.get_acceptor_from_file(tcl_filename)
#    elif parsing_rule == 'generate_composite_without_name.py':
#        return generate_composite_without_name.get_acceptor_from_file(tcl_filename) 
#    elif parsing_rule == 'generate_star.py':
#        return generate_star.get_acceptor_from_file(tcl_filename)
#    elif parsing_rule == 'generate_sequence_with_name.py':
#        return generate_sequence_with_name.get_acceptor_from_file(tcl_filename)
#    elif parsing_rule == 'generate_plus.py':
#        return generate_plus.get_acceptor_from_file(tcl_filename)
#    elif parsing_rule == 'generate_composite_without_name.py':
#        return generate_composite_without_name.get_acceptor_from_file(tcl_filename)
    
    print ("%s rule not defined from %s") %(parsing_rule, tcl_filename)

    raise 'Invalid option'



def get_acceptor_from_file(tcl_name):
    tcl_filename = tcl_name + '.tcl'
    return get_acceptor_from_tcl_file_name(tcl_filename)

# TODO : use hash table
def is_punct_rule(rule):
    for x in config.punct_rule:
        if (rule == x):
            return True
    return False

class rule_error_exception(BaseException):
    pass

