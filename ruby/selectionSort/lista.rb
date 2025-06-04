require_relative 'selection_sort'
require_relative 'registro'

class Lista
  attr_reader :dados
  
  def initialize
    @dados = []
  end

  def adicionar(registro)
    @dados.push(registro)
  end

  def ordenar_por(campo = :user_id)
    SelectionSort.sort(@dados, campo)
  end

  def carregar_dados(caminho_arquivo)
    File.foreach(caminho_arquivo) do |linha|
      adicionar(Registro.new(linha))
    end
  end
end

if __FILE__ == $0
  lista = Lista.new
  lista.carregar_dados('../../100.dat')
  puts "Ordenado por timestamp:"
  puts lista.ordenar_por(:timestamp).map(&:to_s)
end