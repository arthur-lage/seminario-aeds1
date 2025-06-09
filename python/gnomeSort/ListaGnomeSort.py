import time
from GnomeSort import gnome_sort

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
    total = 0
    for i in range(10):
        ratings = read_ratings("../../datasets/10000.dat")
    
        if ratings is not None:
            start = time.perf_counter()
            
            gnome_sort(ratings)
            
            end = time.perf_counter()
            time_spent = (end - start) * 1000  # Convertendo para milissegundos
            total += time_spent
            
    
    print(f"\nMedia: {(total / 10):.5f} ms")

if __name__ == "__main__":
    main()