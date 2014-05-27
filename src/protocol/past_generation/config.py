
name_prefix = 'CAst'
name_ast = name_prefix
name_ast_upper = name_ast.upper()
name_ast_parser = ("%sParser") %(name_ast)
name_ast_parser_upper = name_ast_parser.upper()
name_parser_header = ("%s.h") %(name_ast_parser)
name_parser_cpp = ("%s.cpp") %(name_ast_parser)
name_ast_header = ("%s.h") %(name_ast)
name_ast_cpp = ("%s.cpp") %(name_ast)
name_generate_base = '../generate_base.py'
name_generate_unit = '../generate_unit.py'

punct_rule = ['.', '[', ']', ',', '{', '}',
              '=', '(', ')', ':', '?', ';',
              '>', '<', '@', '*', '+', '-',
              '!', '|', '%', '^', '&', '/',
              '~',
              'assert', 
              'else', 
              'goto',
              'read',
              'write',
              'check',
              'false',
              'if',
              'true',
              ]
