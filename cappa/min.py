code = '''
память1 = ввести(число)
память2 = ввести(число)

если память1 < память2 то 
    вывести(память1)
    конец
кон
если память1 > память2 то
    вывести(память2)
    конец
кон
вывести(память1)
'''

def interpreter(tokens):
    mem1 = 0
    mem2 = 0
    mem3 = 0
    index = 1
    block = True
    i = 0
    while(i < len(tokens)):
        #print(tokens[i])
        if(tokens[i] == 'память1'):
            index = 1
        elif(tokens[i] == 'память2'):
            index = 2
        elif(tokens[i] == 'память3'):
            index = 3
        elif(tokens[i] == '='):
            block = False
        elif(tokens[i] == 'ввести'):
            if(tokens[i + 1] == 'число'):
                if(index == 1):
                    mem1 = int(input())
                elif(index == 2):
                    mem2 = int(input())
                elif(index == 3):
                    mem3 = int(input())
                i += 1
        elif(tokens[i] == 'если'):
            index1 = 1
            index2 = 1
            if(tokens[i + 1] == 'память1'):
                index1 = mem1
            elif(tokens[i + 1] == 'память2'):
                index1 = mem2
            elif(tokens[i + 1] == 'память3'):
                index1 = mem3
            if(tokens[i + 3] == 'память1'):
                index2 = mem1
            elif(tokens[i + 3] == 'память2'):
                index2 = mem2
            elif(tokens[i + 3] == 'память3'):
                index2 = mem3
            if(tokens[i + 2] == '='):
                if(index1 != index2):
                    while(tokens[i] != 'кон'):
                        i += 1
            elif(tokens[i + 2] == '>'):
                if(not(index1 > index2)):
                    while(tokens[i] != 'кон'):
                        i += 1
            elif(tokens[i + 2] == '<'):
                if(not(index1 < index2)):
                    while(tokens[i] != 'кон'):
                        i += 1
        elif(tokens[i] == 'вывести'):
            if(tokens[i + 1] == 'память1'):
                print(mem1)
            elif(tokens[i + 1] == 'память2'):
                print(mem2)
            elif(tokens[i + 1] == 'память3'):
                print(mem3)
            i += 1
        elif(tokens[i] == 'конец'):
            break
        i += 1
    
def lexer(code):
    tokens = []
    comand = ''
    for i in range(len(code)):
        if(code[i] == ' ' or code[i] == '(' or code[i] == ')' or code[i] == '\n'):
           tokens.append(comand)
           comand = ''
        else:
           #print(comand)
           comand = comand + code[i]
    tok = []
    for i in range(len(tokens)):
        if(tokens[i] != ''):
            tok.append(tokens[i])
    return tok

tokens = lexer(code)
#print(tokens)
interpreter(tokens)
