MAX_LINE_LENGTH = 256

class Rating
  attr_accessor :user_id, :movie_id, :rating, :timestamp
  
  def initialize(user_id, movie_id, rating, timestamp)
    @user_id = user_id
    @movie_id = movie_id
    @rating = rating
    @timestamp = timestamp
  end
end

def read_ratings(filename)
  begin
    ratings = []
    File.foreach(filename) do |line|
      line = line.strip
      next if line.empty?
      
      parts = line.split(',')
      next if parts.size < 4
      
      user_id = parts[0].to_i
      movie_id = parts[1].to_i
      rating = parts[2].to_f
      timestamp = parts[3].to_i
      
      ratings << Rating.new(user_id, movie_id, rating, timestamp)
    end
    
    ratings
  rescue StandardError => e
    puts "Erro ao abrir o arquivo #{filename}: #{e}"
    nil
  end
end

def gnome_sort(ratings)
  pos = 0
  count = ratings.size
  
  while pos < count
    if pos == 0 || ratings[pos].timestamp >= ratings[pos-1].timestamp
      pos += 1
    else
      ratings[pos], ratings[pos-1] = ratings[pos-1], ratings[pos]
      pos -= 1
    end
  end
end

def main
  ratings = read_ratings("/home/will/Documentos/AEDS/Seminario/GnomeSort/datasets/100.dat")
  
  if ratings
    start = Time.now
    
    gnome_sort(ratings)
    
    time_spent = (Time.now - start) * 1000
    
    puts "\nTempo de ordenação: #{'%.2f' % time_spent} ms"
  end
end

main if __FILE__ == $0