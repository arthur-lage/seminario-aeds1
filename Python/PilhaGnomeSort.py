import time

MAX_LINE_LENGTH = 256

class Rating:
    def __init__(self, userId, movieId, rating, timestamp):
        self.userId = userId
        self.movieId = movieId
        self.rating = rating
        self.timestamp = timestamp

def read_ratings(filename):
    try:
        with open(filename, 'r') as file:
            ratings = []
            for line in file:
                line = line.strip()
                if not line:
                    continue
                
                parts = line.split(',')
                if len(parts) < 4:
                    continue
                
                userId = int(parts[0])
                movieId = int(parts[1])
                rating = float(parts[2])
                timestamp = int(parts[3])
                
                ratings.append(Rating(userId, movieId, rating, timestamp))
            
            return ratings
    except IOError as e:
        print(f"Erro ao abrir o arquivo {filename}: {e}")
        return None

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

def main():
    ratings = read_ratings("/../../datasets/100.dat")
    
    if ratings is not None:
        start = time.perf_counter()
        
        sorted_ratings = gnome_sort_stack(ratings)
        
        end = time.perf_counter()
        time_spent = (end - start) * 1000
        
        print(f"\nTempo de ordenação: {time_spent:.2f} ms")

if __name__ == "__main__":
    main()