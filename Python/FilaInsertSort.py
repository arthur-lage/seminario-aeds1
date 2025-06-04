import time
from collections import deque

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


def insertion_sort(ratings):
    for i in range(1, len(ratings)):
        chave = ratings[i]
        j = i - 1
        while j >= 0 and ratings[j].timestamp > chave.timestamp:
            ratings[j + 1] = ratings[j]
            j -= 1
        ratings[j + 1] = chave

def main():
    ratings = read_ratings("/home/Heitor/Documentos/Seminario AEDS/datasets/10000.dat")
    
    if ratings is not None:
        start = time.perf_counter()
        
        insertion_sort(ratings)
        
        end = time.perf_counter()
        time_spent = (end - start) * 1000
        
        print(f"\nTempo de ordenação: {time_spent:.2f} ms")

if __name__ == "__main__":
    main()
