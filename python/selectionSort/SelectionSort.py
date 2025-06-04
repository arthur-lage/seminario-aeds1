def selection_sort(ratings):
    n = len(ratings)
    
    for i in range(n):
        min_idx = i
        for j in range(i+1, n):
            if ratings[j].timestamp < ratings[min_idx].timestamp:
                min_idx = j
                
        ratings[i], ratings[min_idx] = ratings[min_idx], ratings[i]
    
    return ratings 
