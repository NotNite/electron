// Renderer side modules, please sort alphabetically.
export const rendererModuleList: ElectronInternal.ModuleEntry[] = [
  { name: 'clipboard', loader: () => require('./clipboard') },
  { name: 'contextBridge', loader: () => require('./context-bridge') },
  { name: 'crashReporter', loader: () => require('./crash-reporter') },
  { name: 'discord', loader: () => process._linkedBinding('electron_renderer_discord') },
  { name: 'ipcRenderer', loader: () => require('./ipc-renderer') },
  { name: 'webFrame', loader: () => require('./web-frame') },
  { name: 'webUtils', loader: () => require('./web-utils') }
];
