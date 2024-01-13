
def peek(stack):
    if len(stack) == 0:
        return ""
    return stack[-1]

def is_palidome(text):
    stack = [] 
    for t in text: 
        p = peek(stack) 
        if p == t:
            stack.pop() 
        else:
            stack.append(t) 
    return len(stack) == 0 

print("abc: ", is_palidome("abc"))
print("bison: ", is_palidome("bison"))
print("corroc: ", is_palidome("corroc"))
print("tattarrattat: ", is_palidome("tattarrattat"))