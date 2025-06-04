public class InsertSort implements Ordenador {
    public void ordenar(Registro[] dados) {
        for (int i = 1; i < dados.length; i++) {
            Registro chave = dados[i];
            int j = i - 1;
            while (j >= 0 && dados[j].chave > chave.chave) {
                dados[j + 1] = dados[j];
                j--;
            }
            dados[j + 1] = chave;
        }
    }
}