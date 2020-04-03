bool agregarOtroElemento(){
    char s;
    cout << "¿Deseas agregar otro elemento?" << endl;
    cin >> s;
    return s == 'S' || s == 's';
}
