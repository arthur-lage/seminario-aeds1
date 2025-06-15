require_relative 'gnome_sort'
require_relative 'registro'
require 'get_process_mem'  # Add this for memory measurement

class Lista
  attr_reader :dados
  
  def initialize
    @dados = []
  end

  def adicionar(registro)
    @dados.push(registro)
  end

  def ordenar_por(campo = :user_id)
    GnomeSort.sort(@dados, campo)
  end

  def carregar_dados(caminho_arquivo)
    File.foreach(caminho_arquivo) do |linha|
      adicionar(Registro.new(linha))
    end
  end
end

if __FILE__ == $0
  total_time = 0.0
  total_memory = 0.0
  mem = GetProcessMem.new  # Initialize memory tracker

  for i in 1..10 do
    # Run GC before measurement for cleaner results
    GC.start
    lista = Lista.new
    lista.carregar_dados('../../datasets/10000.dat')
    
    # Memory before sorting
    mem_before = mem.mb
    
    start = Time.now
    lista.ordenar_por(:timestamp)
    time_spent = (Time.now - start) * 1000
    
    # Memory after sorting
    mem_after = mem.mb
    memory_used = mem_after - mem_before
    
    total_time += time_spent
    total_memory += memory_used
    
    puts "Run #{i}: Time: #{time_spent.round(5)} ms | Memory: #{memory_used.round(5)} MB"
  end

  puts "\nAverage time: #{(total_time/10).round(5)} ms"
  puts "Average memory: #{(total_memory/10).round(5)} MB"
end