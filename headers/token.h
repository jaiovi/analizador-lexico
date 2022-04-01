#ifndef token_h
#define token_h

public class Token{
    private:
        int kind;
        string lexeme;
        int line;
        int entry;
    public:
        Token(int, string, int, int);
        Token(int, string, int);
        string Lexeme();
        int Kind();
        int Line();
        int Entry();
}

#endif