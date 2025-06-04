public class ListaVetor {
    private Registro[] dados;
    private int tamanho;

    public ListaVetor(int capacidade) {
        dados = new Registro[capacidade];
        tamanho = 0;
    }

    public void adicionar(Registro r) {
        if (tamanho == dados.length) {
            redimensionar();
        }
        dados[tamanho++] = r;
    }

    private void redimensionar() {
        Registro[] novo = new Registro[dados.length * 2];
        System.arraycopy(dados, 0, novo, 0, dados.length);
        dados = novo;
    }

    public void remover(Registro r) {
        for (int i = 0; i < tamanho; i++) {
            if (dados[i].chave == r.chave) {
                System.arraycopy(dados, i + 1, dados, i, tamanho - i - 1);
                tamanho--;
                break;
            }
        }
    }

    public void ordenar(Ordenador ordenador) {
        Registro[] copia = new Registro[tamanho];
        System.arraycopy(dados, 0, copia, 0, tamanho);
        ordenador.ordenar(copia);
        System.arraycopy(copia, 0, dados, 0, tamanho);
    }

    public void imprimir() {
        for (int i = 0; i < tamanho; i++) System.out.println(dados[i]);
    }
}