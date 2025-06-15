require_relative 'gnome_sort'
require_relative 'registro'
require 'get_process_mem'  # For memory measurement

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
    
    elementos_ordenados = GnomeSort.sort(elementos, campo)
    
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
  total_time = 0.0
  total_memory = 0.0
  mem = GetProcessMem.new  # Memory tracker

  for i in 1..10 do
    # Clean up memory before measurement
    GC.start
    
    pilha = Pilha.new
    pilha.carregar_dados('/home/Heitor/Documentos/Seminario AEDS with memory/datasets/1000.dat')
    
    # Memory before sorting
    mem_before = mem.mb
    
    start = Time.now
    pilha.ordenar_por(:timestamp)
    time_spent = (Time.now - start) * 1000
    
    # Memory after sorting
    mem_after = mem.mb
    memory_used = mem_after - mem_before
    
    total_time += time_spent
    total_memory += memory_used
    
    puts "Execução #{i}: Tempo: #{time_spent.round(5)} ms | Memória: #{memory_used.round(5)} MB"
  end

  puts "\nMédia de tempo: #{(total_time/10).round(5)} ms"
  puts "Média de memória: #{(total_memory/10).round(5)} MB"
end