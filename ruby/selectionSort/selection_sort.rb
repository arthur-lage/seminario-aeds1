module SelectionSort
  def self.sort(array, campo = :user_id)
    arr = array.dup
    n = arr.length

    (0...n).each do |i|
      min_index = i
      (i+1...n).each do |j|
        if arr[j].send(campo) < arr[min_index].send(campo)
          min_index = j
        end
      end
      arr[i], arr[min_index] = arr[min_index], arr[i]
    end

    arr
  end
end