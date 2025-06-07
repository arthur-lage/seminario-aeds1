module InsertSort
  def self.sort(array, campo = :user_id)
    arr = array.dup

    (1...arr.length).each do |i|
      chave = arr[i]
      j = i - 1

      while j >= 0 && arr[j].send(campo) > chave.send(campo)
        arr[j + 1] = arr[j]
        j -= 1
      end

      arr[j + 1] = chave
    end

    arr
  end
end
