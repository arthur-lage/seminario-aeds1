import time
import tracemalloc
from InsertionSort import insertion_sort

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
    total_time = 0
    total_memory = 0
    
    tracemalloc.start()  # Inicia o rastreamento de memória
    
    for i in range(10):
        ratings = read_ratings("../../datasets/100.dat")
    
        if ratings is not None:
            # Medição de tempo (original)
            start = time.perf_counter()
            insertion_sort(ratings)
            end = time.perf_counter()
            time_spent = (end - start) * 1000
            total_time += time_spent
            
            # Medição de memória (adicionado)
            current_mem, peak_mem = tracemalloc.get_traced_memory()
            total_memory += peak_mem
            
            tracemalloc.reset_peak()  # Reseta para a próxima iteração
    
    tracemalloc.stop()  # Para o rastreamento
    
    print(f"\nMedia tempo: {(total_time / 10):.5f} ms")
    print(f"Media pico memoria: {(total_memory / 10) / 1024:.2f} KiB")  # Convertendo bytes para KiB

if __name__ == "__main__":
    main()