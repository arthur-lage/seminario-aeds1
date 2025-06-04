require_relative 'selection_sort'
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
    
    elementos_ordenados = SelectionSort.sort(elementos, campo)
    
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
  pilha = Pilha.new
  pilha.carregar_dados('../../datasets/100.dat')
  puts "Ordenado por timestamp:"
  puts pilha.ordenar_por(:timestamp).map(&:to_s)
end