# LexicalAnalyzer

# The lexical rules of the language are as follows:
## 1.The language has identifiers, which are defined to be a letter followed by zero or moreletters or numbers. This will be the Token ID.
## 2.The language has integer constants, which are defined to be one or more digits. This willbe the Token INT.
## 3.The language has string constants, which are a double-quoted sequence of characters,all on the same line. This will be the Token STR.
## 4.A string constant can include escape sequences: a backslash followed by a character.The sequence \n should be interpreted as a newline. The sequence \\ should beinterpreted as a backslash. All other escapes should simply be interpreted as thecharacter after the backslash.
## 5.The language has reserved the keywords print, let, if, loop, begin, end. They will beTokens PRINT LET IF LOOP BEGIN END.
## 6.The language has several operators. They are + - * / ! ( )  which will be Tokens PLUSMINUS STAR SLASH BANG LPAREN RPAREN
## 7.The language recognizes a semicolon as the token SC
## 8.A comment is all characters from // to the end of the line; it is ignored and is not returnedas a token. NOTE that a // in the middle of an STR is NOT a comment!1
## 9.Whitespace between tokens can be used for readability, and it serves to delimit tokens.
## 10.An error will be denoted by the ERR token.
## 11.End of file will be denoted by the DONE token.
