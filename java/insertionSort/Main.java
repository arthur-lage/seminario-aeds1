
public class Main {

    public static void main(String[] args) {
        try {
            double totalfp = 0, totalfv = 0, totalpp = 0, totalpv = 0, totallp = 0, totallv = 0;

            Registro[] registros = LeitorDeArquivo.lerRegistros("../../datasets/100.dat");
            System.out.println("Registros lidos: " + registros.length);

            Ordenador ordenador = new InsertSort();
            int capacidade = registros.length;


            for (int i = 0; i < 10; i++) {
                System.out.println("Fila com ponteiros:");
                Fila fila = new Fila();
                for (Registro r : registros) {
                    fila.enfileirar(r);
                }
                long ini = System.nanoTime();
                fila.ordenar(ordenador);
                long fim = System.nanoTime();
                totalfp += (fim - ini) / 1_000_000.0;

            }

            for (int i = 0; i < 10; i++) {
                System.out.println("\nFila com vetor:");
                FilaVetor filaV = new FilaVetor(capacidade);
                for (Registro r : registros) {
                    filaV.enfileirar(r);
                } 
                long ini = System.nanoTime();
                filaV.ordenar(ordenador);
                long fim = System.nanoTime();
                totalfv += (fim - ini) / 1_000_000.0;
                
            }

            for (int i = 0; i < 10; i++) {
                System.out.println("\nPilha com ponteiros:");
                Pilha pilha = new Pilha();
                for (Registro r : registros) {
                    pilha.empilhar(r);
                }
                long ini = System.nanoTime();
                pilha.ordenar(ordenador);
                long fim = System.nanoTime();
                totalpp += (fim - ini) / 1_000_000.0;
                
            }

            for (int i = 0; i < 10; i++) {
                System.out.println("\nPilha com vetor:");
                PilhaVetor pilhaV = new PilhaVetor(capacidade);
                for (Registro r : registros) {
                    pilhaV.empilhar(r);
                }
                long ini = System.nanoTime();
                pilhaV.ordenar(ordenador);
                long fim = System.nanoTime();

                totalpv += (fim - ini) / 1_000_000.0;
                
            }

            for (int i = 0; i < 10; i++) {
                System.out.println("\nLista com ponteiros:");
                Lista lista = new Lista();
                for (Registro r : registros) {
                    lista.adicionar(r);
                }
                long ini = System.nanoTime();
                lista.ordenar(ordenador);
                long fim = System.nanoTime();
                totallp += (fim - ini) / 1_000_000.0;
                
            }

            for (int i = 0; i < 10; i++) {
                System.out.println("\nLista com vetor:");
                ListaVetor listaV = new ListaVetor(capacidade);
                for (Registro r : registros) {
                    listaV.adicionar(r);
                }
                long ini = System.nanoTime();
                listaV.ordenar(ordenador);
                long fim = System.nanoTime();
                totallv += (fim - ini) / 1_000_000.0;
                
            }

            System.out.println("Media FP: " + (totalfp / 10));
            System.out.println("Media FV: " + (totalfv / 10));
            System.out.println("Media PP: " + (totalpp / 10));
            System.out.println("Media PV: " + (totalpv / 10));
            System.out.println("Media LP: " + (totallp / 10));
            System.out.println("Media LV: " + (totallv / 10));
        } catch (Exception e) {
            System.err.println("Erro: " + e.getMessage());
            e.printStackTrace();
        }
    }
}
