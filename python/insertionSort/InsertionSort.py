def insertion_sort(ratings):
    for i in range(1, len(ratings)):
        chave = ratings[i]
        j = i - 1
        while j >= 0 and ratings[j].timestamp > chave.timestamp:
            ratings[j + 1] = ratings[j]
            j -= 1
        ratings[j + 1] = chave


def insertion_sort_stack(ratings):
    stack = []
    
    for rating in ratings:
        
        temp_stack = []
        while stack and stack[-1].timestamp > rating.timestamp:
            temp_stack.append(stack.pop())
        
        
        stack.append(rating)
        
        
        while temp_stack:
            stack.append(temp_stack.pop())
    
    return stack

