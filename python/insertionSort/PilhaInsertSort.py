import time
import tracemalloc
from InsertionSort import insertion_sort_stack

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

def main():
    # Inicia o rastreamento de memória
    tracemalloc.start()
    
    ratings = read_ratings("../../datasets/100.dat")
    
    if ratings is not None:
        # Captura snapshot antes da ordenação
        snapshot1 = tracemalloc.take_snapshot()
        
        start = time.perf_counter()
        sorted_ratings = insertion_sort_stack(ratings)
        end = time.perf_counter()
        
        # Captura snapshot depois da ordenação
        snapshot2 = tracemalloc.take_snapshot()
        
        # Calcula o tempo gasto
        time_spent = (end - start) * 1000
        
        # Calcula a memória utilizada
        stats = snapshot2.compare_to(snapshot1, 'lineno')
        memory_used = sum(stat.size_diff for stat in stats if stat.size_diff > 0)
        
        print(f"\nTempo de ordenação: {time_spent:.5f} ms")
        print(f"Memória utilizada: {memory_used / 1024:.2f} KiB")  # Convertendo bytes para KiB
    
    # Para o rastreamento de memória
    tracemalloc.stop()

if __name__ == "__main__":
    main()