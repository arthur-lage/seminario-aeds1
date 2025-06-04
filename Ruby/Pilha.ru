MAX_LINE_LENGTH = 256

class Rating
  attr_accessor :userId, :movieId, :rating, :timestamp
  
  def initialize(userId, movieId, rating, timestamp)
    @userId = userId
    @movieId = movieId
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
      
      userId = parts[0].to_i
      movieId = parts[1].to_i
      rating = parts[2].to_f
      timestamp = parts[3].to_i
      
      ratings << Rating.new(userId, movieId, rating, timestamp)
    end
    
    ratings
  rescue IOError => e
    puts "Erro ao abrir o arquivo #{filename}: #{e}"
    nil
  end
end

def gnome_sort_stack(ratings)
  stack = []
  temp_stack = []
  
  ratings.each { |rating| stack.push(rating) }
  
  while !stack.empty?
    current = stack.pop
    
    while !temp_stack.empty? && temp_stack.last.timestamp > current.timestamp
      stack.push(temp_stack.pop)
    end
    
    temp_stack.push(current)
  end
  
  temp_stack
end

def main
  ratings = read_ratings("/home/will/Documentos/AEDS/Seminario/GnomeSort/datasets/100.dat")
  
  if ratings
    start = Time.now
    
    sorted_ratings = gnome_sort_stack(ratings)
    
    time_spent = (Time.now - start) * 1000
    
    puts "\nTempo de ordenação: #{time_spent.round(2)} ms"
  end
end

main if __FILE__ == $0