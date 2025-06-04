public class Main {
    public static void main(String[] args) {
        try {
            Registro[] registros = LeitorDeArquivo.lerRegistros("/home/Heitor/Documentos/Seminario AEDS/datasets/10000.dat");
            System.out.println("Registros lidos: " + registros.length);
            
            Ordenador ordenador = new InsertSort();
            int capacidade = registros.length; // Capacidade dinâmica

            System.out.println("Fila com ponteiros:");
            Fila fila = new Fila();
            for (Registro r : registros) fila.enfileirar(r);
            long ini = System.nanoTime();
            fila.ordenar(ordenador);
            long fim = System.nanoTime();
            // fila.imprimir(); // Comentado para não imprimir 1.000.000 de linhas
            System.out.printf("Tempo de ordenação: %.4f ms%n", (fim - ini) / 1_000_000.0);

            System.out.println("\nFila com vetor:");
            FilaVetor filaV = new FilaVetor(capacidade);
            for (Registro r : registros) filaV.enfileirar(r);
            ini = System.nanoTime();
            filaV.ordenar(ordenador);
            fim = System.nanoTime();
            // filaV.imprimir();
            System.out.printf("Tempo de ordenação: %.4f ms%n", (fim - ini) / 1_000_000.0);

            System.out.println("\nPilha com ponteiros:");
            Pilha pilha = new Pilha();
            for (Registro r : registros) pilha.empilhar(r);
            ini = System.nanoTime();
            pilha.ordenar(ordenador);
            fim = System.nanoTime();
            // pilha.imprimir();
            System.out.printf("Tempo de ordenação: %.4f ms%n", (fim - ini) / 1_000_000.0);

            System.out.println("\nPilha com vetor:");
            PilhaVetor pilhaV = new PilhaVetor(capacidade);
            for (Registro r : registros) pilhaV.empilhar(r);
            ini = System.nanoTime();
            pilhaV.ordenar(ordenador);
            fim = System.nanoTime();
            // pilhaV.imprimir();
            System.out.printf("Tempo de ordenação: %.4f ms%n", (fim - ini) / 1_000_000.0);

            System.out.println("\nLista com ponteiros:");
            Lista lista = new Lista();
            for (Registro r : registros) lista.adicionar(r);
            ini = System.nanoTime();
            lista.ordenar(ordenador);
            fim = System.nanoTime();
            // lista.imprimir();
            System.out.printf("Tempo de ordenação: %.4f ms%n", (fim - ini) / 1_000_000.0);

            System.out.println("\nLista com vetor:");
            ListaVetor listaV = new ListaVetor(capacidade);
            for (Registro r : registros) listaV.adicionar(r);
            ini = System.nanoTime();
            listaV.ordenar(ordenador);
            fim = System.nanoTime();
            // listaV.imprimir();
            System.out.printf("Tempo de ordenação: %.4f ms%n", (fim - ini) / 1_000_000.0);

        } catch (Exception e) {
            System.err.println("Erro: " + e.getMessage());
            e.printStackTrace();
        }
    }
}