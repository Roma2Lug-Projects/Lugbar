# Lugbar
Porting in C del programma di @Iaio99 NFC-Emulator. Invia una email alla casella di posta del bar del lug per indicare l'acquisto di un prodotto.

### Perché hai fatto questo porting in C da Python ?
![IT STINKS!](https://imgur.com/GAplSMG.gif)

# Installazione

Dal file .deb per Ubuntu/Debian nella sezione Release oppure installazione manuale:
```
    git clone https://github.com/Roma2LUG-Projects/lugbar.git
    cd lugbar
    sudo make install
```
## Dipendenze 
- wget
- msmtp

# File di configurazione
- /etc/lugbar/item.txt lista dei prodotti disponibili.
- /etc/msmtprc file di configurazione di msmtp per l'invio delle email:
```
defaults
syslog LOG_MAIL
auth on
tls on
aliases /etc/aliases
Example with GMAIL
account lugbar
host smtp.gmail.com
port 465
tls on
tls_starttls off
from "tuo nome"
user example@gmail.com
password "password"
set_from_header on
```
Se usi un account Gmail devi generare una password per le app https://myaccount.google.com/apppasswords
