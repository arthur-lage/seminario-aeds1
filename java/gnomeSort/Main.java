import java.lang.management.ManagementFactory;
import java.lang.management.MemoryMXBean;
import java.lang.management.MemoryUsage;

public class Main {

    public static void main(String[] args) {
        try {
            double totalfp = 0, totalfv = 0, totalpp = 0, totalpv = 0, totallp = 0, totallv = 0;
            double memfp = 0, memfv = 0, mempp = 0, mempv = 0, memlp = 0, memlv = 0;
            Registro[] registros = LeitorDeArquivo.lerRegistros("../../datasets/100000.dat");
            System.out.println("Registros lidos: " + registros.length);

            Ordenador ordenador = new GnomeSort();
            int capacidade = registros.length;
            MemoryMXBean memoryBean = ManagementFactory.getMemoryMXBean();

            for (int i = 0; i < 10; i++) {
                System.gc(); // Run garbage collector before measurement
                System.out.println("Fila com ponteiros:");
                Fila fila = new Fila();
                for (Registro r : registros) {
                    fila.enfileirar(r);
                }
                
                MemoryUsage before = memoryBean.getHeapMemoryUsage();
                long ini = System.nanoTime();
                fila.ordenar(ordenador);
                long fim = System.nanoTime();
                MemoryUsage after = memoryBean.getHeapMemoryUsage();
                
                totalfp += (fim - ini) / 1_000_000.0;
                memfp += (after.getUsed() - before.getUsed()) / (1024.0 * 1024.0); // Convert to MB
            }

            for (int i = 0; i < 10; i++) {
                System.gc();
                System.out.println("\nFila com vetor:");
                FilaVetor filaV = new FilaVetor(capacidade);
                for (Registro r : registros) {
                    filaV.enfileirar(r);
                }
                
                MemoryUsage before = memoryBean.getHeapMemoryUsage();
                long ini = System.nanoTime();
                filaV.ordenar(ordenador);
                long fim = System.nanoTime();
                MemoryUsage after = memoryBean.getHeapMemoryUsage();
                
                totalfv += (fim - ini) / 1_000_000.0;
                memfv += (after.getUsed() - before.getUsed()) / (1024.0 * 1024.0);
            }

            for (int i = 0; i < 10; i++) {
                System.gc();
                System.out.println("\nPilha com ponteiros:");
                Pilha pilha = new Pilha();
                for (Registro r : registros) {
                    pilha.empilhar(r);
                }
                
                MemoryUsage before = memoryBean.getHeapMemoryUsage();
                long ini = System.nanoTime();
                pilha.ordenar(ordenador);
                long fim = System.nanoTime();
                MemoryUsage after = memoryBean.getHeapMemoryUsage();
                
                totalpp += (fim - ini) / 1_000_000.0;
                mempp += (after.getUsed() - before.getUsed()) / (1024.0 * 1024.0);
            }

            for (int i = 0; i < 10; i++) {
                System.gc();
                System.out.println("\nPilha com vetor:");
                PilhaVetor pilhaV = new PilhaVetor(capacidade);
                for (Registro r : registros) {
                    pilhaV.empilhar(r);
                }
                
                MemoryUsage before = memoryBean.getHeapMemoryUsage();
                long ini = System.nanoTime();
                pilhaV.ordenar(ordenador);
                long fim = System.nanoTime();
                MemoryUsage after = memoryBean.getHeapMemoryUsage();
                
                totalpv += (fim - ini) / 1_000_000.0;
                mempv += (after.getUsed() - before.getUsed()) / (1024.0 * 1024.0);
            }

            for (int i = 0; i < 10; i++) {
                System.gc();
                System.out.println("\nLista com ponteiros:");
                Lista lista = new Lista();
                for (Registro r : registros) {
                    lista.adicionar(r);
                }
                
                MemoryUsage before = memoryBean.getHeapMemoryUsage();
                long ini = System.nanoTime();
                lista.ordenar(ordenador);
                long fim = System.nanoTime();
                MemoryUsage after = memoryBean.getHeapMemoryUsage();
                
                totallp += (fim - ini) / 1_000_000.0;
                memlp += (after.getUsed() - before.getUsed()) / (1024.0 * 1024.0);
            }

            for (int i = 0; i < 10; i++) {
                System.gc();
                System.out.println("\nLista com vetor:");
                ListaVetor listaV = new ListaVetor(capacidade);
                for (Registro r : registros) {
                    listaV.adicionar(r);
                }
                
                MemoryUsage before = memoryBean.getHeapMemoryUsage();
                long ini = System.nanoTime();
                listaV.ordenar(ordenador);
                long fim = System.nanoTime();
                MemoryUsage after = memoryBean.getHeapMemoryUsage();
                
                totallv += (fim - ini) / 1_000_000.0;
                memlv += (after.getUsed() - before.getUsed()) / (1024.0 * 1024.0);
            }

            System.out.println("\nMédias de tempo (ms):");
            System.out.println("Media FP: " + (totalfp / 10));
            System.out.println("Media FV: " + (totalfv / 10));
            System.out.println("Media PP: " + (totalpp / 10));
            System.out.println("Media PV: " + (totalpv / 10));
            System.out.println("Media LP: " + (totallp / 10));
            System.out.println("Media LV: " + (totallv / 10));

            System.out.println("\nMédias de memória (MB):");
            System.out.println("Memória FP: " + (memfp / 10));
            System.out.println("Memória FV: " + (memfv / 10));
            System.out.println("Memória PP: " + (mempp / 10));
            System.out.println("Memória PV: " + (mempv / 10));
            System.out.println("Memória LP: " + (memlp / 10));
            System.out.println("Memória LV: " + (memlv / 10));

        } catch (Exception e) {
            System.err.println("Erro: " + e.getMessage());
            e.printStackTrace();
        }
    }
}