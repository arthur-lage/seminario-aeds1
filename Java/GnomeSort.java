public class GnomeSort implements Ordenador {
    public void ordenar(Registro[] dados) {
        int index = 0;
        
        while (index < dados.length) {
            if (index == 0 || dados[index].chave >= dados[index - 1].chave) {
                index++;
            } else {
                Registro temp = dados[index];
                dados[index] = dados[index - 1];
                dados[index - 1] = temp;
                index--;
            }
        }
    }
}