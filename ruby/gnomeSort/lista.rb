MAX_LINE_LENGTH = 256

require_relative 'gnome_sort'
require_relative 'rating'

def main
  ratings = ReadRatings.read_ratings("../../datasets/100.dat")
  
  if ratings
    start = Time.now
    
    GnomeSort.gnome_sort(ratings)
    
    time_spent = (Time.now - start) * 1000
    
    puts "\nTempo de ordenação: #{'%.2f' % time_spent} ms"
  end
end

main if __FILE__ == $0