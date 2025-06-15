import time
from collections import deque
from InsertionSort import insertion_sort
import tracemalloc

class Rating:
    def __init__(self, userId, movieId, rating, timestamp):
        self.userId = userId
        self.movieId = movieId
        self.rating = rating
        self.timestamp = timestamp

def read_ratings(filename):
    try:
        with open(filename, 'r') as file:
            ratings = deque()
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

def main():
    # Inicia o rastreamento de memória
    tracemalloc.start()
    
    ratings = read_ratings("../../datasets/100000.dat")
    
    if ratings is not None:
        # Tira um snapshot antes da ordenação
        snapshot1 = tracemalloc.take_snapshot()
        
        start = time.perf_counter()
        insertion_sort(ratings)
        end = time.perf_counter()
        
        # Tira um snapshot depois da ordenação
        snapshot2 = tracemalloc.take_snapshot()
        
        # Calcula a diferença de memória
        top_stats = snapshot2.compare_to(snapshot1, 'lineno')
        total_memory = sum(stat.size_diff for stat in top_stats)
        
        time_spent = (end - start) * 1000
        
        print(f"\nTempo de ordenação: {time_spent:.5f} ms")
        print(f"Memória utilizada durante a ordenação: {total_memory / 1024:.2f} KiB")
        
        # Mostra as alocações detalhadas (opcional)
    tracemalloc.stop()

if __name__ == "__main__":
    main()