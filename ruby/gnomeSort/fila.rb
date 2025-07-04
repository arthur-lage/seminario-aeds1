require_relative 'gnome_sort'
require_relative 'registro'

class Fila
  attr_reader :dados
  
  def initialize
    @dados = []
  end

  def enfileirar(registro)
    @dados.push(registro)
  end

  def desenfileirar
    @dados.shift
  end

  def ordenar_por(campo = :user_id)
    elementos = []
    while @dados.any?
      elementos << desenfileirar
    end
    
    elementos_ordenados = GnomeSort.sort(elementos, campo)
    
    elementos_ordenados.each { |e| enfileirar(e) }
    elementos_ordenados
  end

  def carregar_dados(caminho_arquivo)
    File.foreach(caminho_arquivo) do |linha|
      enfileirar(Registro.new(linha))
    end
  end
end

if __FILE__ == $0
  total = 0
  
  for i in 1..10 do
    fila = Fila.new
    fila.carregar_dados('../../datasets/10000.dat')
    
    start = Time.now
    
    fila.ordenar_por(:timestamp)
    
    time_spent = (Time.now - start) * 1000
    total += time_spent
  end

  puts "\nMedia: #{(total/10).round(5)} ms"
end