class Registro
  attr_reader :user_id, :movie_id, :rating, :timestamp

  def initialize(linha)
    campos = linha.chomp.split(',')
    @user_id = campos[0].to_i
    @movie_id = campos[1].to_i
    @rating = campos[2].to_f
    @timestamp = campos[3].to_i
  end

  def to_s
    "#{user_id},#{movie_id},#{rating},#{timestamp}"
  end

  def to_a
    [user_id, movie_id, rating, timestamp]
  end
end