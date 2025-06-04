def gnome_sort(ratings):
    pos = 0
    count = len(ratings)
    
    while pos < count:
        if pos == 0 or ratings[pos].timestamp >= ratings[pos-1].timestamp:
            pos += 1
        else:
            ratings[pos], ratings[pos-1] = ratings[pos-1], ratings[pos]
            pos -= 1

def gnome_sort_stack(ratings):
    stack = []
    temp_stack = []
    
    for rating in ratings:
        stack.append(rating)
    
    while stack:
        current = stack.pop()
        
        while temp_stack and temp_stack[-1].timestamp > current.timestamp:
            stack.append(temp_stack.pop())
        
        temp_stack.append(current)
    
    return temp_stack