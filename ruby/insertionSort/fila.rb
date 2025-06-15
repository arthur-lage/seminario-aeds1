require_relative 'Insert_Sort'
require_relative 'registro'
require 'get_process_mem'  # Add this for memory measurement

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
    
    elementos_ordenados = InsertSort.sort(elementos, campo)
    
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
  total_time = 0.0
  total_memory = 0.0
  mem = GetProcessMem.new  # Initialize memory tracker

  total = 0
  
  for i in 1..10 do
    GC.start
    fila = Fila.new
    fila.carregar_dados('../../datasets/10000.dat')
    
    mem_before = mem.mb

    start = Time.now
    
    fila.ordenar_por(:timestamp)
    
    time_spent = (Time.now - start) * 1000
    mem_after = mem.mb
    memory_used = mem_after - mem_before

    total += time_spent
    total_memory += memory_used

    puts "Run #{i}: Time: #{time_spent.round(5)} ms | Memory: #{memory_used.round(5)} MB"
  end

  puts "\nAverage time: #{(total_time/10).round(5)} ms"
  puts "Average memory: #{(total_memory/10).round(5)} MB"
end