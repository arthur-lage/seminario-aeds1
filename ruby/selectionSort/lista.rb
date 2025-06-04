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
  lista.carregar_dados('../../datasets/100.dat')

  start = Time.now
  
  lista.ordenar_por(:timestamp)

  time_spent = (Time.now - start) * 1000
  puts "\nTempo de ordenação: #{time_spent.round(2)} ms"
end