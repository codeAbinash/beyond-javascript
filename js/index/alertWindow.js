export default class AlertWin {
  #win;
  constructor(message, callback = () => {}) {
    this.message = message;
    this.callback = callback;
  }

  show() {
    this.#win = document.createElement('div');
    this.#win.classList.add('alertWindow');

    const alertMessage = document.createElement('div');
    alertMessage.classList.add('alertMessage');

    const heading = document.createElement('h3');
    heading.classList.add('heading');
    heading.innerHTML = this.message.heading || 'Beyond JvaScript';

    const text = document.createElement('p');
    text.classList.add('text');
    text.innerHTML = this.message.text || 'Welcome to Beyond JavaScript';

    const buttonDiv = document.createElement('div');
    buttonDiv.classList.add('btnsDiv');

    const button = document.createElement('button');
    button.classList.add('press');
    button.innerHTML = this.message.btnTxt || 'OK';
    button.addEventListener('click', () => {
      this.callback();
      this.hide();
    });

    alertMessage.appendChild(heading);
    alertMessage.appendChild(text);

    buttonDiv.appendChild(button);

    alertMessage.appendChild(buttonDiv);

    this.#win.appendChild(alertMessage);

    document.body.appendChild(this.#win);

    this.#win.style.display = 'grid';
    document.body.style.overflow = 'hidden';
    setTimeout(() => {
      this.#win.style.opacity = 1;
    }, 400);
  }

  hide() {
    this.#win.style.opacity = 0;
    setTimeout(() => {
      this.#win.style.display = 'none';
      document.body.style.overflow = 'auto';
      this.#win.remove();
    }, 400);
  }
}
