.import QtQuick.LocalStorage as Storage

const DEFAULT_APPLICATION_LANGUAGE = "en"
const DEFAULT_AUTO_SAVE_STATE = "false"

// Dials database connection and provides lazy initialization
function getDatabase(){
    const db = Storage.LocalStorage.openDatabaseSync("SimpleRead", "1.0", "Local storage for internal logic of 'SimpleRead'", 10000000);
    db.transaction(function(tx){
        tx.executeSql("CREATE TABLE IF NOT EXISTS KeyValue(key TEXT UNIQUE, value TEXT)");
    })
    return db
}

// Returns a language which is currently used in the application
function getCurrentLanguage(){
    const db = getDatabase();

    let result = DEFAULT_APPLICATION_LANGUAGE;
    db.readTransaction(
        function(tx) {
            const rs = tx.executeSql('SELECT value FROM KeyValue WHERE key = "language"');
            if (rs.rows.length !== 0){
                result = rs.rows.item(0).value;
            }
        })
    return result;
}

// Sets a language which is currently used in the application
function setCurrentLanguage(language){
    const db = getDatabase();
    db.transaction(
        function(tx){
            tx.executeSql('INSERT OR REPLACE INTO KeyValue VALUES(?, ?)', [ "language", language ]);
        })
}

// Returns a state of 'AutoSave' option which is currently used in the application
function getAutoSave(){
    const db = getDatabase();

    let result = DEFAULT_AUTO_SAVE_STATE;
    db.readTransaction(
        function(tx) {
            const rs = tx.executeSql('SELECT value FROM KeyValue WHERE key = "autoSave"');
            if (rs.rows.length !== 0){
                result = rs.rows.item(0).value;
            }
        })
    return result;
}

// Sets a state of 'AutoSave' option which is currently used in the application
function setAutoSave(state){
    const db = getDatabase();
    db.transaction(
        function(tx){
            tx.executeSql('INSERT OR REPLACE INTO KeyValue VALUES(?, ?)', [ "autoSave", state]);
        })
}
