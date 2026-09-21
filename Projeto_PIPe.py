import multiprocessing
from time import sleep

def processo_filho(conexao):
    print("[FILHO] Processo filho iniciado. Aguardando mensagem do pipe...")

    mensagem = conexao.recv()  # Recebe a mensagem do pipe
    print(f"[FILHO] Mensagem recebida do pipe: {mensagem}")
    conexao.close()  # Fecha a conexão do pipe

    print("[FILHO] Processo filho finalizado. Programa encerrado.")

if __name__ == "__main__":
        con_pai, con_filho = multiprocessing.Pipe()  # Cria um pipe para comunicação entre processos
        p = multiprocessing.Process(target=processo_filho, args=(con_filho,))  # Cria o processo filho
        p.start()  # Inicia o processo filho

        sleep(1)  # Aguarda um momento antes de enviar a mensagem

        texto = "Olá, processo filho! Esta é uma mensagem do processo pai."
        print(f"[PAI] Enviando mensagem para o processo filho: {texto}")

        con_pai.send(texto)  # Envia a mensagem para o processo filho
        con_pai.close()  # Fecha a conexão do pipe no processo pai
        p.join()  # Aguarda o término do processo filho

        print("[PAI] Processo filho finalizado. Programa encerrado.")