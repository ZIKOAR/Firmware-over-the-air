const char *htmlPage = R"rawliteral(
<!DOCTYPE html>
<html lang="en">
	<head>
		<meta charset="UTF-8" />
		<meta name="viewport" content="width=device-width, initial-scale=1.0" />
		<title>STM32 FOTA - ESP32-Server</title>
		<style>
			:root {
				--back_color: #f1f3e0;
				--hover_color: #d1e1a7;
				--brand_color: #7c9872;
				--text_color: #546351;
			}

			* {
				box-sizing: border-box;
				margin: 0;
				padding: 0;
				font-family: system-ui, sans-serif;
			}

			*::-webkit-scrollbar {
				background: transparent;
				width: 20px;
			}

			*::-webkit-scrollbar-thumb {
				cursor: pointer;

				background: var(--text_color);
				background-clip: content-box;
				border: 2px solid transparent;
				border-radius: 0.25rem;
			}

			body {
				background: var(--back_color);
				padding-block: 1rem;

				.main-container {
					min-height: calc(100vh - 2rem);
					width: calc(100% - 2rem);
					max-width: 1000px;
					margin-inline: auto;

					display: flex;
					flex-direction: column;
					gap: 1rem;

					h1 {
						user-select: none;
						color: var(--text_color);
					}

					.main-content {
						flex: 1;
						overflow: hidden;

						display: flex;
						flex-direction: column;
						gap: 0.5rem;

						label {
							user-select: none;
							cursor: pointer;

							width: 100%;
							font-size: 1.25rem;
							font-weight: 600;
							text-align: center;

							background: var(--hover_color);
							color: var(--text_color);
							border: 1px solid currentColor;
							padding: 0.25rem;
							border-radius: 0.25rem;
							transition: 0.2s ease-in-out;

							&:hover {
								color: var(--back_color);
								background: var(--text_color);
								border-color: var(--text_color);
							}
						}

						.buttons {
							display: grid;
							grid-template-columns: repeat(2, 1fr);
							gap: 0.25rem;

							button {
								user-select: none;
								cursor: pointer;
								outline: none;

								font-size: 1.25rem;
								font-weight: 600;
								text-align: center;

								background: var(--hover_color);
								color: var(--text_color);
								border: 1px solid currentColor;
								padding: 0.25rem;
								border-radius: 0.25rem;
								transition: 0.2s ease-in-out;

								&#clear-file {
									grid-column: 1 / -1;
								}

								&:hover {
									color: var(--back_color);
									background: var(--text_color);
									border-color: var(--text_color);
								}
							}
						}

						textarea {
							flex: 1;
							resize: none;
							outline: none;
							padding: 0.25rem;

							font-size: 1rem;
							font-weight: 600;
							color: var(--text_color);
							border: 1px solid var(--text_color);
							border-radius: 0.25rem;
							background: transparent;
						}
					}
				}
			}
		</style>
	</head>
	<body>
		<div class="main-container">
			<h1>STM32 FOTA - ESP32-Server</h1>
			<div class="main-content">
				<label for="bin-file" id="bin-file-label"
					>Select a BIN file (.bin):</label
				>
				<input
					type="file"
					name="bin-file"
					id="bin-file"
					accept=".bin"
					maxlength="1"
					required
					hidden
				/>

				<div class="buttons">
					<button type="button" id="log-file">Log file</button>
					<button type="button" id="send-file">Send file</button>
					<button type="button" id="clear-file">Clear (Size: Empty)</button>
				</div>

				<textarea
					id="bin-file-content"
					placeholder="BIN (.bin) file content"
					readonly
					rows="10"
				></textarea>
			</div>
		</div>

		<script>
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
							hexStr +=
								bytes[i].toString(16).padStart(2, "0").toUpperCase() + " ";
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
		</script>
	</body>
</html>
)rawliteral";
