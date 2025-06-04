MAX_LINE_LENGTH = 256

require_relative 'gnome_sort'
require_relative 'rating'

def main
  ratings = ReadRatings.read_ratings("../../datasets/100.dat")
  
  if ratings
    start = Time.now
    
    sorted_ratings = GnomeSort.gnome_sort_stack(ratings)
    
    time_spent = (Time.now - start) * 1000
    
    puts "\nTempo de ordenação: #{time_spent.round(2)} ms"
  end
end

main if __FILE__ == $0