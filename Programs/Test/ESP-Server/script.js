document.addEventListener("DOMContentLoaded", () => {
	const binFileLabel = document.getElementById("bin-file-label");
	const binFileInput = document.getElementById("bin-file");
	const binFileContent = document.getElementById("bin-file-content");
	let binFile = null;

	const clearFileButton = document.getElementById("clear-file");
	const logFileButton = document.getElementById("log-file");
	const sendFileButton = document.getElementById("send-file");

	/* --------------- */

	binFileInput.addEventListener("cancel", () => {
		binFileInput.value = "";
		binFile = null;
		binFileLabel.innerText = "Select a BIN file (.bin):";
	});

	binFileInput.addEventListener("change", () => {
		if (binFileInput.files.length === 1) {
			binFile = binFileInput.files[0];
			binFileLabel.innerText = `Current BIN file: ${binFile.name}`;
			clearFileButton.innerText = `Clear (Size: ${getBinFileSize()} KBytes)`;
		}
	});

	/* --------------- */

	clearFileButton.addEventListener("click", () => {
		if (!binFile) return;

		binFileInput.value = "";
		binFile = null;
		binFileContent.value = "";
		binFileLabel.innerText = "Select a BIN file (.bin):";
		clearFileButton.innerText = "Clear (Size: Empty)";
	});

	logFileButton.addEventListener("click", () => {
		if (!binFile) return;

		const reader = new FileReader();
		reader.readAsArrayBuffer(binFile);

		reader.onload = function (e) {
			const bytes = new Uint8Array(e.target.result);
			binFileContent.value = convertBytesToHexString(bytes, false);
		};

		reader.onerror = function () {
			binFileContent.value = "Error reading file!";
		};
	});

	sendFileButton.addEventListener("click", () => {
		if (!binFile) return;

		const reader = new FileReader();
		reader.readAsArrayBuffer(binFile);

		reader.onload = async function (e) {
			const bytes = new Uint8Array(e.target.result);
			const text = convertBytesToHexString(bytes, true);
			console.log("Start FOTA update!");

			fetch("/fota", {
				method: "POST",
				headers: {
					"Content-Type": "text/plain",
				},
				body: text,
			})
				.then((res) => res.text())
				.then((txt) => console.log("ESP32 says:", txt))
				.catch((err) => console.error(err));

			console.log("FOTA update done!");
		};

		reader.onerror = function () {
			console.error("Error reading BIN file before sending!");
		};
	});

	/* --------------- */

	function convertBytesToHexString(bytes, useSingleLineStyle = false) {
		let hexStr = "";

		if (useSingleLineStyle) {
			for (let i = 0; i < bytes.length; i++) {
				hexStr += bytes[i].toString(16).padStart(2, "0").toUpperCase() + " ";
			}
		} else {
			for (let i = 0; i < bytes.length; i++) {
				hexStr += bytes[i].toString(16).padStart(2, "0").toUpperCase();
				if ((i + 1) % 16 === 0) hexStr += "\n";
				else if ((i + 1) % 4 === 0) hexStr += "   ";
			}
		}

		return hexStr;
	}

	function getBinFileSize() {
		if (!binFile) return;
		return Math.round((binFile.size / 1024) * 100) / 100;
	}
});
