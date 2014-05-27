parser grammar SourceText ;

import ModuleDeclaration ;

source_text : (description)+ ;

description : module_declaration
//            | udp_declaration 
            ;
