# 🍝 Philosophers - Dining Philosophers Problem

**42 Firenze Project | C Multithreading**  
*Simulazione del problema dei filosofi: gestione concorrente con thread, mutex e sincronizzazione precisa. Bonus escluso.*  

---

## 📋 Specifiche  
✅ **Funzionalità Base**:  
   - Simulazione concorrente con `pthread`  
   - Ogni filosofo pensa, mangia e dorme in un ciclo  
   - Protezione delle risorse condivise (forchette) con `mutex`  
   - Terminazione della simulazione se un filosofo muore o tutti hanno mangiato N volte  
   - Log delle azioni con timestamp preciso  

✅ **Tecnologie**:  
   - `C` (standard C99)  
   - Threading via `pthread.h`  
   - Temporizzazione con `gettimeofday()`  
   - Makefile con regole `all`, `clean`, `fclean`, `re`  
   - Compilazione con `-Wall -Wextra -Werror`  

✅ **Conformità**:  
   - Nessuna variabile globale  
   - Norminette-compliant  
   - Gestione della memoria senza perdite  
   - Precisione temporale e sincronizzazione garantite  

---

## ⚙️ Esecuzione  
### ▶️ Compilazione  
```bash
make        # Compila il programma
make clean  # Rimuove i file oggetto
make fclean # Rimuove anche l'eseguibile
make re     # Ricompila da zero
```

---

## 🧪 Utilizzo  
```bash
./philo number_of_philosophers time_to_die time_to_eat time_to_sleep [number_of_times_each_philosopher_must_eat]
```

📌 **Argomenti**:
- `number_of_philosophers`: numero di filosofi (e forchette)
- `time_to_die`: tempo massimo (in ms) che un filosofo può restare senza mangiare
- `time_to_eat`: tempo (in ms) impiegato per mangiare
- `time_to_sleep`: tempo (in ms) impiegato per dormire
- `number_of_times_each_philosopher_must_eat` *(opzionale)*: numero minimo di volte che ogni filosofo deve mangiare

📌 **Esempi**:
```bash
./philo 5 800 200 200
./philo 5 800 200 200 7
```

---

## 🗃 Output Previsto  
Durante l'esecuzione, ogni azione è stampata nel formato:

```
[timestamp_in_ms] [philosopher_number] is [action]
```

Esempio:
```text
234 1 has taken a fork  
235 1 has taken a fork  
236 1 is eating  
437 1 is sleeping  
638 1 is thinking  
```

---

## ℹ️ Note Finali  
- Nessun uso di variabili globali è consentito  
- Tutta la memoria allocata dinamicamente viene liberata correttamente  
- L'output è sincronizzato tra thread per evitare sovrapposizioni  
- La gestione del tempo è fondamentale: una simulazione scorretta può portare alla morte errata di un filosofo o a comportamenti imprevisti  
- Il progetto è pensato per far comprendere le problematiche reali nella concorrenza: deadlock, starvation, race condition  

---
