public class PilhaVetor {
    private Registro[] dados;
    private int topo;

    public PilhaVetor(int capacidade) {
        dados = new Registro[capacidade];
        topo = 0;
    }

    public void empilhar(Registro r) {
        if (topo == dados.length) {
            redimensionar();
        }
        dados[topo++] = r;
    }

    private void redimensionar() {
        Registro[] novo = new Registro[dados.length * 2];
        System.arraycopy(dados, 0, novo, 0, dados.length);
        dados = novo;
    }

    public Registro desempilhar() {
        return topo == 0 ? null : dados[--topo];
    }

    public void ordenar(Ordenador ordenador) {
        Registro[] copia = new Registro[topo];
        System.arraycopy(dados, 0, copia, 0, topo);
        ordenador.ordenar(copia);
        System.arraycopy(copia, 0, dados, 0, topo);
    }

    public void imprimir() {
        for (int i = 0; i < topo; i++) System.out.println(dados[i]);
    }
}