module ReadRatings
    def self.read_ratings(filename)
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
end