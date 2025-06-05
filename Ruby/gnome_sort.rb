module GnomeSort
  def self.sort(array, campo = :user_id)
    arr = array.dup
    index = 0

    while index < arr.length
      if index == 0 || arr[index].send(campo) >= arr[index - 1].send(campo)
        index += 1
      else
        arr[index], arr[index - 1] = arr[index - 1], arr[index]
        index -= 1
      end
    end

    arr
  end
end