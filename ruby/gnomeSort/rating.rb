class Rating
    attr_accessor :userId, :movieId, :rating, :timestamp
    
    def initialize(userId, movieId, rating, timestamp)
      @userId = userId
      @movieId = movieId
      @rating = rating
      @timestamp = timestamp
    end
  end