#ifndef DEBUG_H
#define DEBUG_H

#define DEBUG_EXPR(expr) do { std::cerr << "*Debug: " << #expr << " : " << (expr) << std::endl; } while(0)

#endif // DEBUG_H
