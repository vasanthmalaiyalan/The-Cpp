#ifndef TOKENSTREAM_H
#define TOKENSTREAM_H

class Token {
    public:
       char kind;
       double values;
       Token(char k);
       Token(char k, double v);
};

class Token_stream {
    public:
       Token get();

       void putback(Token t);

    private:
       bool full = false;
       
       Token buffer {'0'};
};

#endif