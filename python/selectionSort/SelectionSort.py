def selection_sort(ratings):
    n = len(ratings)
    
    for i in range(n):
        min_idx = i
        for j in range(i+1, n):
            if ratings[j].timestamp < ratings[min_idx].timestamp:
                min_idx = j
                
        ratings[i], ratings[min_idx] = ratings[min_idx], ratings[i]
    
    return ratings 

def selection_sort_stack(ratings):
    unsorted = list(ratings) 
    sorted_stack = []
    
    while unsorted:
        min_index = 0
        for i in range(1, len(unsorted)):
            if unsorted[i].timestamp < unsorted[min_index].timestamp:
                min_index = i
        
        sorted_stack.append(unsorted.pop(min_index))
    
    return sorted_stack