require_relative 'Insert_Sort'
require_relative 'registro'

class Pilha
  attr_reader :dados
  
  def initialize
    @dados = []
  end

  def empilhar(registro)
    @dados.push(registro)
  end

  def desempilhar
    @dados.pop
  end

  def ordenar_por(campo = :user_id)
    elementos = []
    while @dados.any?
      elementos << desempilhar
    end
    
    elementos_ordenados = InsertSort.sort(elementos, campo)
    
    elementos_ordenados.each { |e| empilhar(e) }
    elementos_ordenados
  end

  def carregar_dados(caminho_arquivo)
    File.foreach(caminho_arquivo) do |linha|
      empilhar(Registro.new(linha))
    end
  end
end

if __FILE__ == $0
  total = 0
  
  for i in 1..10 do
  pilha = Pilha.new
  pilha.carregar_dados('../../datasets/10000.dat')

  start = Time.now
  
  pilha.ordenar_por(:timestamp)

  time_spent = (Time.now - start) * 1000
  total += time_spent
end

puts "\nMedia: #{(total/10).round(5)} ms"
end