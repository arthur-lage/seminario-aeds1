public class SelectionSort implements Ordenador {
    public void ordenar(Registro[] dados) {
        for (int i = 0; i < dados.length - 1; i++) {
            int indiceMinimo = i;
            for (int j = i + 1; j < dados.length; j++) {
                if (dados[j].chave < dados[indiceMinimo].chave) {
                    indiceMinimo = j;
                }
            }
            
            Registro temp = dados[indiceMinimo];
            dados[indiceMinimo] = dados[i];
            dados[i] = temp;
        }
    }
}