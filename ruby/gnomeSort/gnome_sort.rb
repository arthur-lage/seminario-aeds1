module GnomeSort
  def self.gnome_sort(ratings)
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
  end


  def self.gnome_sort_stack(ratings)
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
end